#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Core/Factory/imageconverterfactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),

    _conversionTypesModel(Q_NULLPTR),
    _mainSettingsController(Q_NULLPTR)
{
    ui->setupUi(this);

    initModels();
    initWidgets();
    initControllers();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::initModels() {
    initConversionTypesModel();
    initForcedFormatsModel();
}

void MainWindow::initConversionTypesModel() {
    QStringList model;

    model << tr("Obrazek (pojedynczy)");
    model << tr("Obrazki z katalogu");
    model << tr("Obrazki z listy (dowolne)");
    model << tr("Obrazki z listy (marki)");
    model << tr("Obrazki z listy (produkty)");

    _conversionTypesModel = new QStringListModel(model, this);
}

void MainWindow::initForcedFormatsModel() {
    QStringList model;

    model << tr("Brak");
    model << tr(".png");
    model << tr(".jpg");

    _forcedFormatsModel = new QStringListModel(model, this);
}



void MainWindow::initWidgets() {
    ui->conversionType->setModel(_conversionTypesModel);
    ui->forcedFormatComboBox->setModel(_forcedFormatsModel);
}



void MainWindow::initControllers() {
    initConversionController();
    initConversionSettingsController();
    initMainSettingsController();
    initImageRecordsController();
}

void MainWindow::initConversionController() {
    _imagesConverter = new ImagesConverter(_imageRecordsModel, _mainSettingsModel, this);
    _imagesConverter->setImageConverter(ImageConverterFactory::getInstance().createSquareImageConverter(_conversionSettingsModel, _mainSettingsModel));

    _conversionController.setConversionModel(&_conversionModel);
    _conversionController.setConversionSettingsModel(&_conversionSettingsModel);
    _conversionController.setImageRecordsModel(&_imageRecordsModel);
    _conversionController.setMainSettingsModel(&_mainSettingsModel);

    _conversionController.connectStartAction(ui->actionRun);
    _conversionController.connectCancelAction(ui->actionCancel);

    _conversionController.connectStartAction(ui->runButton);
    _conversionController.connectCancelAction(ui->cancelButton);

    _conversionController.connectProgress(ui->progressProgressBar);

    _conversionController.connectImagesConverter(_imagesConverter);
}

void MainWindow::initConversionSettingsController() {
    _conversionSettingsController.setConversionModel(&_conversionModel);
    _conversionSettingsController.setConversionSettingsModel(&_conversionSettingsModel);

    _conversionSettingsController.connectXRatioSpinBox(ui->xRatio);
    _conversionSettingsController.connectYRatioSpinBox(ui->yRatio);

    _conversionSettingsController.connectMarginSpinBox(ui->marginSpinBox);
    _conversionSettingsController.connectMarginSlider(ui->marginSlider);

    _conversionSettingsController.connectAlphaToleranceSpinBox(ui->alphaToleranceSpinBox);
    _conversionSettingsController.connectAlphaToleranceSlider(ui->alphaToleranceSlider);

    _conversionSettingsController.connectColorToleranceSpinBox(ui->colorToleranceSpinBox);
    _conversionSettingsController.connectColorToleranceSlider(ui->colorToleranceSlider);

    _conversionSettingsController.connectColorView(ui->colorView);
    _conversionSettingsController.connectColorButton(ui->colorButton);

    _conversionSettingsController.connectClearColorCheckBox(ui->clearColorCheckBox);
}

void MainWindow::initMainSettingsController() {
    _mainSettingsController = new MainSettingsController(this);
    _mainSettingsController->setConversionModel(&_conversionModel);
    _mainSettingsController->setMainSettingsModel(&_mainSettingsModel);

    _mainSettingsController->connectConversionType(ui->conversionType);

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
}

void MainWindow::initImageRecordsController() {
    _imageRecordsController = new ImageRecordsController(_imageRecordsModel, this);

    _imageRecordsController->connectImageRecords(ui->tableView);
}
