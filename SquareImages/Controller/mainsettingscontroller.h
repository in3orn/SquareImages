#ifndef MAINSETTINGSCONTROLLER_H
#define MAINSETTINGSCONTROLLER_H

#include <QObject>

#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>

#include "Model/conversionmodel.h"
#include "Model/mainsettingsmodel.h"

class MainSettingsController : public QObject
{
    Q_OBJECT
public:
    explicit MainSettingsController(QObject *parent = 0);

    ConversionModel *getConversionModel() const;
    MainSettingsModel *getMainSettingsModel() const;

    void setConversionModel(ConversionModel *model);
    void setMainSettingsModel(MainSettingsModel *model);



    void connectConversionType(QComboBox *widget);

    void connectOutputPathLineEdit(QLineEdit *widget);
    void connectSourceFileLineEdit(QLineEdit *widget);
    void connectSourcePathLineEdit(QLineEdit *widget);
    void connectListFileLineEdit(QLineEdit *widget);

    void connectCheckSubdirs(QCheckBox *widget);
    void connectReplaceExisting(QCheckBox *widget);

    void connectOutputPathPushButton(QPushButton *widget);
    void connectSourceFilePushButton(QPushButton *widget);
    void connectSourcePathPushButton(QPushButton *widget);
    void connectListFilePushButton(QPushButton *widget);

    void connectForcedFormatComboBox(QComboBox *widget);

signals:

public slots:
    void selectOutputPath();
    void selectSourceFile();
    void selectSourcePath();
    void selectListFile();

    void refreshWidgets();

protected:
    void refreshConversionTypeComboBox();

    void refreshOutputPathLineEdit();
    void refreshSourceFileLineEdit();
    void refreshSourcePathLineEdit();
    void refreshListFileLineEdit();

    void refreshOutputPathPushButton();
    void refreshSourceFilePushButton();
    void refreshSourcePathPushButton();
    void refreshListFilePushButton();

    void refreshCheckSubdirs();
    void refreshReplaceExisting();

    void refreshForcedFormatComboBox();

protected:
    ConversionModel *_conversionModel;
    MainSettingsModel *_mainSettingsModel;

    QComboBox *_conversionTypeComboBox;

    QLineEdit *_outputPathLineEdit;
    QLineEdit *_sourceFileLineEdit;
    QLineEdit *_sourcePathLineEdit;
    QLineEdit *_listFileLineEdit;

    QCheckBox *_checkSubdirs;
    QCheckBox *_replaceExisting;

    QPushButton *_outputPathPushButton;
    QPushButton *_sourceFilePushButton;
    QPushButton *_sourcePathPushButton;
    QPushButton *_listFilePushButton;

    QComboBox *_forcedFormatComboBox;
};

#endif // MAINSETTINGSCONTROLLER_H
