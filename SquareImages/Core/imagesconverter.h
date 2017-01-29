#ifndef IMAGESCONVERTER_H
#define IMAGESCONVERTER_H

#include <QThread>


#include "imageconverter.h"
#include "Model/imagerecordsmodel.h"
#include "Model/mainsettingsmodel.h"

class ImagesConverter : public QThread
{
    Q_OBJECT

public:
    ImagesConverter(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent = Q_NULLPTR);

    virtual ~ImagesConverter();


    ImageConverter *getImageConverter() const;
    void setImageConverter(ImageConverter *imageConverter);

signals:
    void processStarted();
    void processCanceled();
    void processFinished();

    void progressChanged(double progress);

    void errorReported(const QString &errorMessage);

protected:
    virtual void run();

    virtual void preparePath(QString const &path);

private:
    ImageRecordsModel &_imageRecordsModel;
    MainSettingsModel &_mainSettingsModel;

    ImageConverter *_imageConverter;
};

#endif // IMAGESCONVERTER_H
