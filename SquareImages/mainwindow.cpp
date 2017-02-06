#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Core/Factory/imageconverterfactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),

    _mainSettingsController(Q_NULLPTR)
{
    ui->setupUi(this);

    initWidgets();
    initControllers();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::initWidgets() {
    ui->conversionTypeComboBox->setModel(new QStringListModel(MainSettingsModel::convertsionTypeNames, this));
    ui->forcedFormatComboBox->setModel(new QStringListModel(MainSettingsModel::forcedFormatNames, this));

    ui->converterTypeComboBox->setModel(new QStringListModel(ConversionSettingsModel::converterTypeNames, this));
    ui->horizontalAlignmentComboBox->setModel(new QStringListModel(ConversionSettingsModel::horizontalAlignmentNames, this));
    ui->verticalAlignmentComboBox->setModel(new QStringListModel(ConversionSettingsModel::verticalAlignmentNames, this));

    ui->maxScaleStrategyComboBox->setModel(new QStringListModel(ConversionSettingsModel::maxScaleStrategyNames, this));
    ui->minScaleStrategyComboBox->setModel(new QStringListModel(ConversionSettingsModel::minScaleStrategyNames, this));
}



void MainWindow::initControllers() {
    initConversionController();
    initConversionSettingsController();
    initMainSettingsController();
    initImageRecordsController();
}

void MainWindow::initConversionController() {
    _conversionController.setConversionModel(&_conversionModel);
    _conversionController.setConversionSettingsModel(&_conversionSettingsModel);
    _conversionController.setImageRecordsModel(&_imageRecordsModel);
    _conversionController.setMainSettingsModel(&_mainSettingsModel);

    _conversionController.connectStartAction(ui->actionRun);
    _conversionController.connectCancelAction(ui->actionCancel);

    _conversionController.connectStartAction(ui->runButton);
    _conversionController.connectCancelAction(ui->cancelButton);

    _conversionController.connectProgress(ui->progressProgressBar);
}

void MainWindow::initConversionSettingsController() {
    _conversionSettingsController.setConversionModel(&_conversionModel);
    _conversionSettingsController.setConversionSettingsModel(&_conversionSettingsModel);


    _conversionSettingsController.connectConverterTypeComboBox(ui->converterTypeComboBox);

    _conversionSettingsController.connectHorizontalAlignmentComboBox(ui->horizontalAlignmentComboBox);
    _conversionSettingsController.connectVerticalAlignmentComboBox(ui->verticalAlignmentComboBox);

    _conversionSettingsController.connectMaxScaleStrategyComboBox(ui->maxScaleStrategyComboBox);
    _conversionSettingsController.connectMaxScaleValueSpinBox(ui->maxScaleValueSpinBox);

    _conversionSettingsController.connectMinScaleStrategyComboBox(ui->minScaleStrategyComboBox);
    _conversionSettingsController.connectMinScaleValueSpinBox(ui->minScaleValueSpinBox);

    _conversionSettingsController.connectXRatioSpinBox(ui->xRatio);
    _conversionSettingsController.connectYRatioSpinBox(ui->yRatio);

    _conversionSettingsController.connectMarginSpinBox(ui->marginSpinBox);
    _conversionSettingsController.connectMarginSlider(ui->marginSlider);

    _conversionSettingsController.connectTextSizeSpinBox(ui->textSizeSpinBox);
    _conversionSettingsController.connectTextSizeSlider(ui->textSizeSlider);

    _conversionSettingsController.connectAlphaToleranceSpinBox(ui->alphaToleranceSpinBox);
    _conversionSettingsController.connectAlphaToleranceSlider(ui->alphaToleranceSlider);

    _conversionSettingsController.connectColorToleranceSpinBox(ui->backgroundColorToleranceSpinBox);
    _conversionSettingsController.connectColorToleranceSlider(ui->backgroundColorToleranceSlider);

    _conversionSettingsController.connectClearColorCheckBox(ui->clearColorCheckBox);

    _conversionSettingsController.connectBackgroundColorView(ui->backgroundColorView);
    _conversionSettingsController.connectBackgroundColorButton(ui->backgroundColorButton);

    _conversionSettingsController.connectTextColorView(ui->textColorView);
    _conversionSettingsController.connectTextColorButton(ui->textColorButton);

    _conversionSettingsController.connectTextFontLineEdit(ui->textFontLineEdit);
    _conversionSettingsController.connectTextFontButton(ui->textFontButton);
}

void MainWindow::initMainSettingsController() {
    _mainSettingsController = new MainSettingsController(this);
    _mainSettingsController->setConversionModel(&_conversionModel);
    _mainSettingsController->setMainSettingsModel(&_mainSettingsModel);


    _mainSettingsController->connectConversionType(ui->conversionTypeComboBox);

    _mainSettingsController->connectOutputPathLineEdit(ui->outputPathLineEdit);
    _mainSettingsController->connectSourceFileLineEdit(ui->sourceFileLineEdit);
    _mainSettingsController->connectSourcePathLineEdit(ui->sourcePathLineEdit);
    _mainSettingsController->connectListFileLineEdit(ui->listFileLineEdit);

    _mainSettingsController->connectCheckSubdirs(ui->checkSubdirs);
    _mainSettingsController->connectReplaceExisting(ui->replaceExisting);

    _mainSettingsController->connectOutputPathPushButton(ui->outputPathPushButton);
    _mainSettingsController->connectSourceFilePushButton(ui->sourceFilePushButton);
    _mainSettingsController->connectSourcePathPushButton(ui->sourcePathPushButton);
    _mainSettingsController->connectListFilePushButton(ui->listFilePushButton);

    _mainSettingsController->connectForcedFormatComboBox(ui->forcedFormatComboBox);

    _mainSettingsController->connectImageQualitySlider(ui->imageQualitySlider);
    _mainSettingsController->connectImageQualitySpinBox(ui->imageQualitySpinBox);
}

void MainWindow::initImageRecordsController() {
    _imageRecordsController = new ImageRecordsController(_imageRecordsModel, this);

    _imageRecordsController->connectImageRecords(ui->tableView);
}
