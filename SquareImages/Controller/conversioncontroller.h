#ifndef CONVERSIONCONTROLLER_H
#define CONVERSIONCONTROLLER_H

#include <QThread>

#include <QProgressBar>
#include <QPushButton>
#include <QAction>

#include "Model/conversionmodel.h"
#include "Model/conversionsettingsmodel.h"
#include "Model/imagerecordsmodel.h"
#include "Model/mainsettingsmodel.h"

#include "Core/filerecord.h"

#include "Core/squareimageconverter.h"

#include "Core/filerecordscreator.h"
#include "Core/imagesconverter.h"

class ConversionController : public QThread
{
    Q_OBJECT

public:
    explicit ConversionController(QObject *parent = 0);

    ConversionModel *getConversionModel() const;
    void setConversionModel(ConversionModel *conversionModel);

    ConversionSettingsModel *getConversionSettingsModel() const;
    void setConversionSettingsModel(ConversionSettingsModel *conversionSettingsModel);

    ImageRecordsModel *getImageRecordsModel() const;
    void setImageRecordsModel(ImageRecordsModel *imageRecordsModel);

    MainSettingsModel *getMainSettingsModel() const;
    void setMainSettingsModel(MainSettingsModel *mainSettingsModel);



    void connectProgress(QProgressBar *widget);

    void connectStartAction(QPushButton *widget);
    void connectCancelAction(QPushButton *widget);

    void connectStartAction(QAction *action);
    void connectCancelAction(QAction *action);

    void connectFileRecordsCreator(FileRecordsCreator *creator);
    void connectImagesConverter(ImagesConverter *converter);

signals:

public slots:
    void start();
    void cancel();


    void finishCreation();
    void finishConversion();

    void cancelCreation();
    void cancelConversion();

    void updateFileRecordProgress(double progress);
    void updateImageProgress(double progress);

    void refreshWidgets();

protected:
    bool validate() const;

    void updateProgress();

    void refreshProgressProgressBar();

    void refreshStartButton();
    void refreshCancelButton();

    void refreshStartAction();
    void refreshCancelAction();

private:
    ConversionModel *_conversionModel;
    ConversionSettingsModel *_conversionSettingsModel;
    ImageRecordsModel *_imageRecordsModel;
    MainSettingsModel *_mainSettingsModel;


    QProgressBar *_progressProgressBar;

    QPushButton *_startButton;
    QPushButton *_cancelButton;

    QAction *_startAction;
    QAction *_cancelAction;

    FileRecordsCreator *_fileRecordsCreator;
    ImagesConverter *_imagesConverter;

    double _fileRecordProgress;
    double _imageProgress;
};

#endif // CONVERSIONCONTROLLER_H
