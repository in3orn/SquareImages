#include "mainsettingscontroller.h"

#include <QFileDialog>

#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>

MainSettingsController::MainSettingsController(QObject *parent) : QObject(parent)
{

}





ConversionModel *MainSettingsController::getConversionModel() const {
    return _conversionModel;
}

MainSettingsModel *MainSettingsController::getMainSettingsModel() const {
    return _mainSettingsModel;
}

void MainSettingsController::setConversionModel(ConversionModel *conversionModel) {
    _conversionModel = conversionModel;

    connect(_conversionModel, &ConversionModel::runningChanged, this, MainSettingsController::refreshWidgets);
}

void MainSettingsController::setMainSettingsModel(MainSettingsModel *mainSettingsModel) {
    _mainSettingsModel = mainSettingsModel;
}





void MainSettingsController::connectConversionType(QComboBox *widget) {
    _conversionTypeComboBox = widget;
    _conversionTypeComboBox->setCurrentIndex(_mainSettingsModel->getConversionType());
    refreshConversionTypeComboBox();

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            _mainSettingsModel, static_cast<void(MainSettingsModel::*)(int)>(&MainSettingsModel::setConversionType));
    connect(_mainSettingsModel, static_cast<void(MainSettingsModel::*)(int)>(&MainSettingsModel::conversionTypeChanged),
            widget, &QComboBox::setCurrentIndex);

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainSettingsController::refreshWidgets);
}

void MainSettingsController::connectOutputPathLineEdit(QLineEdit *widget) {
    _outputPathLineEdit = widget;
    _outputPathLineEdit->setText(_mainSettingsModel->getOutputPath());
    refreshOutputPathLineEdit();

    connect(widget, &QLineEdit::textChanged, _mainSettingsModel, &MainSettingsModel::setOutputPath);
    connect(_mainSettingsModel, &MainSettingsModel::outputPathChanged, widget, &QLineEdit::setText);
}

void MainSettingsController::connectSourceFileLineEdit(QLineEdit *widget) {
    _sourceFileLineEdit = widget;
    _sourceFileLineEdit->setText(_mainSettingsModel->getSourceFile());
    refreshSourceFileLineEdit();

    connect(widget, &QLineEdit::textChanged, _mainSettingsModel, &MainSettingsModel::setSourceFile);
    connect(_mainSettingsModel, &MainSettingsModel::sourceFileChanged, widget, &QLineEdit::setText);
}

void MainSettingsController::connectSourcePathLineEdit(QLineEdit *widget) {
    _sourcePathLineEdit = widget;
    _sourcePathLineEdit->setText(_mainSettingsModel->getSourcePath());
    refreshSourcePathLineEdit();

    connect(widget, &QLineEdit::textChanged, _mainSettingsModel, &MainSettingsModel::setSourcePath);
    connect(_mainSettingsModel, &MainSettingsModel::sourcePathChanged, widget, &QLineEdit::setText);
}

void MainSettingsController::connectListFileLineEdit(QLineEdit *widget) {
    _listFileLineEdit = widget;
    _listFileLineEdit->setText(_mainSettingsModel->getListFile());
    refreshListFileLineEdit();

    connect(widget, &QLineEdit::textChanged, _mainSettingsModel, &MainSettingsModel::setListFile);
    connect(_mainSettingsModel, &MainSettingsModel::listFileChanged, widget, &QLineEdit::setText);
}

void MainSettingsController::connectCheckSubdirs(QCheckBox *widget) {
    _checkSubdirs = widget;
    _checkSubdirs->setChecked(_mainSettingsModel->isCheckSubdirs());
    refreshCheckSubdirs();

    connect(widget, &QCheckBox::toggled, _mainSettingsModel, &MainSettingsModel::setCheckSubdirs);
    connect(_mainSettingsModel, &MainSettingsModel::checkSubdirsChanged, widget, &QCheckBox::setChecked);
}

void MainSettingsController::connectReplaceExisting(QCheckBox *widget) {
    _replaceExisting = widget;
    _replaceExisting->setChecked(_mainSettingsModel->isReplaceExisting());
    refreshReplaceExisting();

    connect(widget, &QCheckBox::toggled, _mainSettingsModel, &MainSettingsModel::setReplaceExisting);
    connect(_mainSettingsModel, &MainSettingsModel::replaceExistingChanged, widget, &QCheckBox::setChecked);
}

void MainSettingsController::connectOutputPathPushButton(QPushButton *widget) {
    _outputPathPushButton = widget;
    refreshOutputPathPushButton();

    connect(widget, &QPushButton::clicked, this, &MainSettingsController::selectOutputPath);
}

void MainSettingsController::connectSourceFilePushButton(QPushButton *widget) {
    _sourceFilePushButton = widget;
    refreshSourceFilePushButton();

    connect(widget, &QPushButton::clicked, this, &MainSettingsController::selectSourceFile);
}

void MainSettingsController::connectSourcePathPushButton(QPushButton *widget) {
    _sourcePathPushButton = widget;
    refreshSourcePathPushButton();

    connect(widget, &QPushButton::clicked, this, &MainSettingsController::selectSourcePath);
}

void MainSettingsController::connectListFilePushButton(QPushButton *widget) {
    _listFilePushButton = widget;
    refreshListFilePushButton();

    connect(widget, &QPushButton::clicked, this, &MainSettingsController::selectListFile);
}

void MainSettingsController::connectForcedFormatComboBox(QComboBox *widget) {
    _forcedFormatComboBox = widget;
    _forcedFormatComboBox->setCurrentIndex(_mainSettingsModel->getForcedFormat());
    refreshForcedFormatComboBox();

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            _mainSettingsModel, static_cast<void(MainSettingsModel::*)(int)>(&MainSettingsModel::setForcedFormat));

    connect(_mainSettingsModel, static_cast<void(MainSettingsModel::*)(int)>(&MainSettingsModel::forcedFormatChanged),
            widget, &QComboBox::setCurrentIndex);
}

void MainSettingsController::connectImageQualitySlider(QSlider *widget) {
    _imageQualitySlider = widget;
    _imageQualitySlider->setValue(_mainSettingsModel->getImageQuality());
    refreshImageQualitySlider();

    connect(widget, &QSlider::valueChanged, _mainSettingsModel, &MainSettingsModel::setImageQuality);
    connect(_mainSettingsModel, &MainSettingsModel::imageQualityChanged, widget, &QSlider::setValue);
}

void MainSettingsController::connectImageQualitySpinBox(QSpinBox *widget) {
    _imageQualitySpinBox = widget;
    _imageQualitySpinBox->setValue(_mainSettingsModel->getImageQuality());
    refreshImageQualitySpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _mainSettingsModel, &MainSettingsModel::setImageQuality);
    connect(_mainSettingsModel, &MainSettingsModel::imageQualityChanged, widget, &QSpinBox::setValue);
}




void MainSettingsController::selectOutputPath() {
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);

    int result = dialog.exec();

    if(result) {
        QStringList files = dialog.selectedFiles();
        if(files.size() > 0) {
            _mainSettingsModel->setOutputPath(files.first());
        }
    }
}

void MainSettingsController::selectSourceFile() {
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("Images (*.png; *.jpg; *.jpeg; *.gif; *.tif; *.tiff; *.bmp)"));

    int result = dialog.exec();

    if(result) {
        QStringList files = dialog.selectedFiles();
        if(files.size() > 0) {
            _mainSettingsModel->setSourceFile(files.first());
        }
    }
}

void MainSettingsController::selectSourcePath() {
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::Directory);

    int result = dialog.exec();

    if(result) {
        QStringList files = dialog.selectedFiles();
        if(files.size() > 0) {
            _mainSettingsModel->setSourcePath(files.first());
        }
    }
}

void MainSettingsController::selectListFile() {
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("List files (*.txt; *.csv)"));

    int result = dialog.exec();

    if(result) {
        QStringList files = dialog.selectedFiles();
        if(files.size() > 0) {
            _mainSettingsModel->setListFile(files.first());
        }
    }
}




void MainSettingsController::refreshWidgets() {
    refreshConversionTypeComboBox();

    refreshOutputPathLineEdit();
    refreshSourceFileLineEdit();
    refreshSourcePathLineEdit();
    refreshListFileLineEdit();

    refreshOutputPathPushButton();
    refreshSourceFilePushButton();
    refreshSourcePathPushButton();
    refreshListFilePushButton();

    refreshCheckSubdirs();
    refreshReplaceExisting();

    refreshForcedFormatComboBox();

    refreshImageQualitySlider();
    refreshImageQualitySpinBox();
}


void MainSettingsController::refreshConversionTypeComboBox() {
    _conversionTypeComboBox->setEnabled(!_conversionModel->isRunning());
}


void MainSettingsController::refreshOutputPathLineEdit() {
    _outputPathLineEdit->setEnabled(!_conversionModel->isRunning());
}

void MainSettingsController::refreshSourceFileLineEdit() {
    _sourceFileLineEdit->setEnabled(!_conversionModel->isRunning() &&
                                    (_mainSettingsModel->getConversionType() == MainSettingsModel::ConvertSingleImage ||
                                     _mainSettingsModel->getConversionType() == MainSettingsModel::ConvertTopProductImages));
}

void MainSettingsController::refreshSourcePathLineEdit() {
    _sourcePathLineEdit->setEnabled(!_conversionModel->isRunning() &&
                                    _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertSingleImage &&
                                    _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertTopProductImages);
}

void MainSettingsController::refreshListFileLineEdit() {
    _listFileLineEdit->setEnabled(!_conversionModel->isRunning() &&
                                  _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertSingleImage &&
                                  _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertDirectoryImages);
}


void MainSettingsController::refreshOutputPathPushButton() {
    _outputPathPushButton->setEnabled(!_conversionModel->isRunning());
}

void MainSettingsController::refreshSourceFilePushButton() {
    _sourceFilePushButton->setEnabled(!_conversionModel->isRunning() &&
                                      (_mainSettingsModel->getConversionType() == MainSettingsModel::ConvertSingleImage ||
                                       _mainSettingsModel->getConversionType() == MainSettingsModel::ConvertTopProductImages));
}

void MainSettingsController::refreshSourcePathPushButton() {
    _sourcePathPushButton->setEnabled(!_conversionModel->isRunning() &&
                                      _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertSingleImage &&
                                      _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertTopProductImages);
}

void MainSettingsController::refreshListFilePushButton() {
    _listFilePushButton->setEnabled(!_conversionModel->isRunning() &&
                                    _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertSingleImage &&
                                    _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertDirectoryImages);
}


void MainSettingsController::refreshCheckSubdirs() {
    _checkSubdirs->setEnabled(!_conversionModel->isRunning() &&
                              _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertSingleImage &&
                              _mainSettingsModel->getConversionType() != MainSettingsModel::ConvertTopProductImages);
}

void MainSettingsController::refreshReplaceExisting() {
    _replaceExisting->setEnabled(!_conversionModel->isRunning());
}

void MainSettingsController::refreshForcedFormatComboBox() {
    _forcedFormatComboBox->setEnabled(!_conversionModel->isRunning());
}

void MainSettingsController::refreshImageQualitySlider() {
    _imageQualitySlider->setEnabled(!_conversionModel->isRunning());
}

void MainSettingsController::refreshImageQualitySpinBox() {
    _imageQualitySlider->setEnabled(!_conversionModel->isRunning());
}
