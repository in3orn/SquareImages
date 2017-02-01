#include "conversioncontroller.h"

#include <QMessageBox>

#include <QFile>
#include <QTextStream>

#include "Core/stringutils.h"

#include "Core/Factory/filerecordscreatorfactory.h"
#include "Core/Factory/imageconverterfactory.h"

ConversionController::ConversionController(QObject *parent) : QThread(parent),
    _conversionModel(Q_NULLPTR),
    _conversionSettingsModel(Q_NULLPTR),
    _imageRecordsModel(Q_NULLPTR),
    _mainSettingsModel(Q_NULLPTR),

    _progressProgressBar(Q_NULLPTR),
    _startButton(Q_NULLPTR),
    _cancelButton(Q_NULLPTR),
    _startAction(Q_NULLPTR),
    _cancelAction(Q_NULLPTR),

    _fileRecordsCreator(Q_NULLPTR),
    _imagesConverter(Q_NULLPTR),

    _fileRecordProgress(0),
    _imageProgress(0)
{
}



ConversionModel *ConversionController::getConversionModel() const {
    return _conversionModel;
}

void ConversionController::setConversionModel(ConversionModel *conversionModel) {
    if(_conversionModel) {
        disconnect(_conversionModel, &ConversionModel::runningChanged, this, &ConversionController::refreshWidgets);
    }

    _conversionModel = conversionModel;

    connect(_conversionModel, &ConversionModel::runningChanged, this, &ConversionController::refreshWidgets);
}

ConversionSettingsModel *ConversionController::getConversionSettingsModel() const {
    return _conversionSettingsModel;
}

void ConversionController::setConversionSettingsModel(ConversionSettingsModel *conversionSettingsModel) {
    _conversionSettingsModel = conversionSettingsModel;
}

ImageRecordsModel *ConversionController::getImageRecordsModel() const {
    return _imageRecordsModel;
}

void ConversionController::setImageRecordsModel(ImageRecordsModel *imageRecordsModel) {
    _imageRecordsModel = imageRecordsModel;
}

MainSettingsModel *ConversionController::getMainSettingsModel() const {
    return _mainSettingsModel;
}

void ConversionController::setMainSettingsModel(MainSettingsModel *mainSettingsModel) {
    _mainSettingsModel = mainSettingsModel;
}



void ConversionController::connectProgress(QProgressBar *widget) {
    _progressProgressBar = widget;
    _progressProgressBar->setValue(_conversionModel->getProgress());
    refreshProgressProgressBar();

    connect(_conversionModel, &ConversionModel::progressChanged, widget, &QProgressBar::setValue);
}

void ConversionController::connectStartAction(QPushButton *widget) {
    _startButton = widget;
    refreshStartButton();

    connect(widget, &QPushButton::clicked, this, &ConversionController::start);
}

void ConversionController::connectCancelAction(QPushButton *widget) {
    _cancelButton = widget;
    refreshCancelButton();

    connect(widget, &QPushButton::clicked, this, &ConversionController::cancel);
}

void ConversionController::connectStartAction(QAction *action) {
    _startAction = action;
    refreshStartAction();

    connect(action, &QAction::triggered, this, &ConversionController::start);
}

void ConversionController::connectCancelAction(QAction *action) {
    _cancelAction = action;
    refreshCancelAction();

    connect(action, &QAction::triggered, this, &ConversionController::cancel);
}

void ConversionController::connectFileRecordsCreator(FileRecordsCreator *creator) {
    if(_fileRecordsCreator) {
        disconnect(_fileRecordsCreator, &FileRecordsCreator::processFinished, this, &ConversionController::finishCreation);
        disconnect(_fileRecordsCreator, &FileRecordsCreator::processCanceled, this, &ConversionController::cancelCreation);

        disconnect(_fileRecordsCreator, &FileRecordsCreator::progressChanged, this, &ConversionController::updateFileRecordProgress);

        _fileRecordsCreator->deleteLater();
    }

    _fileRecordsCreator = creator;

    connect(_fileRecordsCreator, &FileRecordsCreator::processFinished, this, &ConversionController::finishCreation);
    connect(_fileRecordsCreator, &FileRecordsCreator::processCanceled, this, &ConversionController::cancelCreation);

    connect(_fileRecordsCreator, &FileRecordsCreator::progressChanged, this, &ConversionController::updateFileRecordProgress);
}

void ConversionController::connectImagesConverter(ImagesConverter *converter) {
    _imagesConverter = converter;

    connect(converter, &ImagesConverter::processFinished, this, &ConversionController::finishConversion);
    connect(converter, &ImagesConverter::processCanceled, this, &ConversionController::cancelConversion);

    connect(converter, &ImagesConverter::progressChanged, this, &ConversionController::updateImageProgress);
}



void ConversionController::start() {
    _fileRecordProgress = 0;
    _imageProgress = 0;

    _conversionModel->setProgress(0);
    _conversionModel->setRunning(true);

    _imageRecordsModel->clear();

    FileRecordsCreator *fileRecordsCreator = FileRecordsCreatorFactory::getInstance().create(*_imageRecordsModel, *_mainSettingsModel);
    connectFileRecordsCreator(fileRecordsCreator);

    ImageConverter *imageConverter = ImageConverterFactory::getInstance().create(*_conversionSettingsModel, *_mainSettingsModel);

    ImagesConverter *imagesConverter = new ImagesConverter(*_imageRecordsModel, *_mainSettingsModel);
    imagesConverter->setImageConverter(imageConverter);

    connectImagesConverter(imagesConverter);

    _fileRecordsCreator->start();
}

void ConversionController::cancel() {
    if(_fileRecordsCreator->isRunning()) {
        _fileRecordsCreator->requestInterruption();
        return;
    }

    if(_imagesConverter->isRunning()) {
        _imagesConverter->requestInterruption();
        return;
    }
}


void ConversionController::finishCreation() {
    _conversionModel->setProgress(10);
    _imagesConverter->start();
}

void ConversionController::finishConversion() {
    _conversionModel->setProgress(100);
    _conversionModel->setRunning(false);
}

void ConversionController::cancelCreation() {
    _conversionModel->setRunning(false);
}

void ConversionController::cancelConversion() {
    _conversionModel->setRunning(false);
}

void ConversionController::updateFileRecordProgress(double progress) {
    _fileRecordProgress = progress;
    updateProgress();
}

void ConversionController::updateImageProgress(double progress) {
    _imageProgress = progress;
    updateProgress();
}



void ConversionController::updateProgress() {
    _conversionModel->setProgress(_fileRecordProgress * 10 + _imageProgress * 90);
}



void ConversionController::refreshWidgets() {
    refreshProgressProgressBar();

    refreshStartButton();
    refreshCancelButton();

    refreshStartAction();
    refreshCancelAction();
}

void ConversionController::refreshProgressProgressBar() {
    _progressProgressBar->setEnabled(_conversionModel->isRunning());
}

void ConversionController::refreshStartButton() {
    _startButton->setEnabled(!_conversionModel->isRunning());
}

void ConversionController::refreshCancelButton() {
    _cancelButton->setEnabled(_conversionModel->isRunning());
}

void ConversionController::refreshStartAction() {
    _startAction->setEnabled(!_conversionModel->isRunning());
}

void ConversionController::refreshCancelAction() {
    _cancelAction->setEnabled(_conversionModel->isRunning());
}
