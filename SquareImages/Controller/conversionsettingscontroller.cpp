#include "conversionsettingscontroller.h"

#include <QColorDialog>

ConversionSettingsController::ConversionSettingsController(QObject *parent) : QObject(parent),

    _conversionModel(Q_NULLPTR),
    _conversionSettingsModel(Q_NULLPTR)
{

}

ConversionModel *ConversionSettingsController::getConversionModel() const {
    return _conversionModel;
}

ConversionSettingsModel *ConversionSettingsController::getConversionSettingsModel() const {
    return _conversionSettingsModel;
}

void ConversionSettingsController::setConversionModel(ConversionModel *conversionModel) {
    if(_conversionModel) {
        disconnect(_conversionModel, &ConversionModel::runningChanged, this, &ConversionSettingsController::refreshWidgets);
    }

    _conversionModel = conversionModel;

    connect(_conversionModel, &ConversionModel::runningChanged, this, &ConversionSettingsController::refreshWidgets);
}

void ConversionSettingsController::setConversionSettingsModel(ConversionSettingsModel *conversionSettingsModel) {
    _conversionSettingsModel = conversionSettingsModel;
}



void ConversionSettingsController::connectXRatioSpinBox(QSpinBox *widget) {
    _xRatioSpinBox = widget;
    _xRatioSpinBox->setValue(_conversionSettingsModel->getXRatio());
    refreshXRadioSpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _conversionSettingsModel, &ConversionSettingsModel::setXRatio);
    connect(_conversionSettingsModel, &ConversionSettingsModel::xRatioChanged, widget, &QSpinBox::setValue);
}

void ConversionSettingsController::connectYRatioSpinBox(QSpinBox *widget) {
    _yRatioSpinBox = widget;
    _yRatioSpinBox->setValue(_conversionSettingsModel->getYRatio());
    refreshYRadioSpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _conversionSettingsModel, &ConversionSettingsModel::setYRatio);
    connect(_conversionSettingsModel, &ConversionSettingsModel::yRatioChanged, widget, &QSpinBox::setValue);
}

void ConversionSettingsController::connectMarginSpinBox(QSpinBox *widget) {
    _marginSpinBox = widget;
    _marginSpinBox->setValue(_conversionSettingsModel->getMargin());
    refreshMarginSpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _conversionSettingsModel, &ConversionSettingsModel::setMargin);
    connect(_conversionSettingsModel, &ConversionSettingsModel::marginChanged, widget, &QSpinBox::setValue);
}

void ConversionSettingsController::connectMarginSlider(QSlider *widget) {
    _marginSlider = widget;
    _marginSlider->setValue(_conversionSettingsModel->getMargin());
    refreshMarginSlider();

    connect(widget, &QSlider::valueChanged, _conversionSettingsModel, &ConversionSettingsModel::setMargin);
    connect(_conversionSettingsModel, &ConversionSettingsModel::marginChanged, widget, &QSlider::setValue);
}

void ConversionSettingsController::connectAlphaToleranceSpinBox(QSpinBox *widget) {
    _alphaToleranceSpinBox = widget;
    _alphaToleranceSpinBox->setValue(_conversionSettingsModel->getAlphaTolerance());
    refreshAlphaToleranceSpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _conversionSettingsModel, &ConversionSettingsModel::setAlphaTolerance);
    connect(_conversionSettingsModel, &ConversionSettingsModel::alphaToleranceChanged, widget, &QSpinBox::setValue);
}

void ConversionSettingsController::connectAlphaToleranceSlider(QSlider *widget) {
    _alphaToleranceSlider = widget;
    _alphaToleranceSlider->setValue(_conversionSettingsModel->getAlphaTolerance());
    refreshAlphaToleranceSlider();

    connect(widget, &QSlider::valueChanged, _conversionSettingsModel, &ConversionSettingsModel::setAlphaTolerance);
    connect(_conversionSettingsModel, &ConversionSettingsModel::alphaToleranceChanged, widget, &QSlider::setValue);
}

void ConversionSettingsController::connectColorToleranceSpinBox(QSpinBox *widget) {
    _colorToleranceSpinBox = widget;
    _colorToleranceSpinBox->setValue(_conversionSettingsModel->getColorTolerance());
    refreshColorToleranceSpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _conversionSettingsModel, &ConversionSettingsModel::setColorTolerance);
    connect(_conversionSettingsModel, &ConversionSettingsModel::colorToleranceChanged, widget, &QSpinBox::setValue);
}

void ConversionSettingsController::connectColorToleranceSlider(QSlider *widget) {
    _colorToleranceSlider = widget;
    _colorToleranceSlider->setValue(_conversionSettingsModel->getAlphaTolerance());
    refreshColorToleranceSlider();

    connect(widget, &QSlider::valueChanged, _conversionSettingsModel, &ConversionSettingsModel::setColorTolerance);
    connect(_conversionSettingsModel, &ConversionSettingsModel::colorToleranceChanged, widget, &QSlider::setValue);
}

void ConversionSettingsController::connectColorView(QGraphicsView *widget) {
    _colorView = widget;
    setColorViewColor(_conversionSettingsModel->getColor());

    connect(_conversionSettingsModel, &ConversionSettingsModel::colorChanged, this, &ConversionSettingsController::setColorViewColor);
}

void ConversionSettingsController::connectColorButton(QPushButton *widget) {
    _colorButton = widget;
    refreshColorButton();

    connect(widget, &QPushButton::clicked, this, &ConversionSettingsController::selectColor);
}

void ConversionSettingsController::connectClearColorCheckBox(QCheckBox *widget) {
    _clearColorCheckBox = widget;
    _clearColorCheckBox->setChecked(_conversionSettingsModel->isClearColor());
    refreshClearColorCheckBox();

    connect(widget, &QCheckBox::toggled, _conversionSettingsModel, &ConversionSettingsModel::setClearColor);
    connect(_conversionSettingsModel, &ConversionSettingsModel::clearColorChanged, widget, &QCheckBox::setChecked);
}




void ConversionSettingsController::selectColor() {
    QColorDialog dialog;

    int result = dialog.exec();

    if(result) {
        _conversionSettingsModel->setColor(dialog.selectedColor());
    }
}

void ConversionSettingsController::setColorViewColor(const QColor &color) {
    _colorView->setStyleSheet("QGraphicsView { background-color: " + color.name() + "; }");
}




void ConversionSettingsController::refreshWidgets() {
    refreshXRadioSpinBox();
    refreshYRadioSpinBox();

    refreshMarginSpinBox();
    refreshMarginSlider();

    refreshAlphaToleranceSpinBox();
    refreshAlphaToleranceSlider();

    refreshColorToleranceSpinBox();
    refreshColorToleranceSlider();

    refreshColorView();
    refreshColorButton();

    refreshClearColorCheckBox();
}

void ConversionSettingsController::refreshXRadioSpinBox() {
    _xRatioSpinBox->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshYRadioSpinBox() {
    _yRatioSpinBox->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshMarginSpinBox() {
    _marginSpinBox->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshMarginSlider() {
    _marginSlider->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshAlphaToleranceSpinBox() {
    _alphaToleranceSpinBox->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshAlphaToleranceSlider() {
    _alphaToleranceSlider->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshColorToleranceSpinBox() {
    _colorToleranceSpinBox->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshColorToleranceSlider() {
    _colorToleranceSlider->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshColorView() {
    _colorView->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshColorButton() {
    _colorButton->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshClearColorCheckBox() {
    _clearColorCheckBox->setEnabled(!_conversionModel->isRunning());
}
