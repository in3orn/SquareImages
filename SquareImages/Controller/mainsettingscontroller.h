#ifndef MAINSETTINGSCONTROLLER_H
#define MAINSETTINGSCONTROLLER_H

#include <QObject>

#include "Model/conversionmodel.h"
#include "Model/mainsettingsmodel.h"

class QCheckBox;
class QComboBox;
class QLineEdit;
class QPushButton;
class QSpinBox;
class QSlider;

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
    void connectNormalizeNames(QCheckBox *widget);

    void connectOutputPathPushButton(QPushButton *widget);
    void connectSourceFilePushButton(QPushButton *widget);
    void connectSourcePathPushButton(QPushButton *widget);
    void connectListFilePushButton(QPushButton *widget);

    void connectForcedFormatComboBox(QComboBox *widget);

    void connectImageQualitySlider(QSlider *widget);
    void connectImageQualitySpinBox(QSpinBox *widget);

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
    void refreshNormalizeNames();

    void refreshForcedFormatComboBox();

    void refreshImageQualitySlider();
    void refreshImageQualitySpinBox();

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
    QCheckBox *_normalizeNames;

    QPushButton *_outputPathPushButton;
    QPushButton *_sourceFilePushButton;
    QPushButton *_sourcePathPushButton;
    QPushButton *_listFilePushButton;

    QComboBox *_forcedFormatComboBox;

    QSlider *_imageQualitySlider;
    QSpinBox *_imageQualitySpinBox;
};

#endif // MAINSETTINGSCONTROLLER_H
