#include "conversionsettingscontroller.h"

#include <QColorDialog>
#include <QFontDialog>

#include <QComboBox>
#include <QSpinBox>
#include <QSlider>
#include <QGraphicsView>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>

#include <QFont>

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



void ConversionSettingsController::connectConverterTypeComboBox(QComboBox *widget) {
    _converterTypeComboBox = widget;
    _converterTypeComboBox->setCurrentIndex(_conversionSettingsModel->getConverterType());
    refreshConverterTypeComboBox();

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            _conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::setConverterType));

    connect(_conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::converterTypeChanged),
            widget, &QComboBox::setCurrentIndex);

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &ConversionSettingsController::refreshWidgets);
}


void ConversionSettingsController::connectHorizontalAlignmentComboBox(QComboBox *widget) {
    _horizontalAlignmentComboBox = widget;
    _horizontalAlignmentComboBox->setCurrentIndex(_conversionSettingsModel->getHorizontalAlignment());
    refreshHorizontalAlignmentComboBox();

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            _conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::setHorizontalAlignment));

    connect(_conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::horizontalAlignmentChanged),
            widget, &QComboBox::setCurrentIndex);
}

void ConversionSettingsController::connectVerticalAlignmentComboBox(QComboBox *widget) {
    _verticalAlignmentComboBox = widget;
    _verticalAlignmentComboBox->setCurrentIndex(_conversionSettingsModel->getVerticalAlignment());
    refreshVerticalAlignmentComboBox();

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            _conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::setVerticalAlignment));

    connect(_conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::verticalAlignmentChanged),
            widget, &QComboBox::setCurrentIndex);
}

void ConversionSettingsController::connectMaxScaleStrategyComboBox(QComboBox *widget) {
    _maxScaleStrategyComboBox = widget;
    _maxScaleStrategyComboBox->setCurrentIndex(_conversionSettingsModel->getMaxScaleStrategy());
    refreshMaxScaleStrategyComboBox();

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            _conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::setMaxScaleStrategy));

    connect(_conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::maxScaleStrategyChanged),
            widget, &QComboBox::setCurrentIndex);

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &ConversionSettingsController::refreshMaxScaleValueSpinBox);
}

void ConversionSettingsController::connectMaxScaleValueSpinBox(QSpinBox *widget) {
    _maxScaleValueSpinBox = widget;
    _maxScaleValueSpinBox->setValue(_conversionSettingsModel->getMaxScaleValue());
    refreshMaxScaleValueSpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _conversionSettingsModel, &ConversionSettingsModel::setMaxScaleValue);
    connect(_conversionSettingsModel, &ConversionSettingsModel::maxScaleValueChanged, widget, &QSpinBox::setValue);
}

void ConversionSettingsController::connectMinScaleStrategyComboBox(QComboBox *widget) {
    _minScaleStrategyComboBox = widget;
    _minScaleStrategyComboBox->setCurrentIndex(_conversionSettingsModel->getMinScaleStrategy());
    refreshMinScaleStrategyComboBox();

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            _conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::setMinScaleStrategy));

    connect(_conversionSettingsModel, static_cast<void(ConversionSettingsModel::*)(int)>(&ConversionSettingsModel::minScaleStrategyChanged),
            widget, &QComboBox::setCurrentIndex);

    connect(widget, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &ConversionSettingsController::refreshMinScaleValueSpinBox);
}

void ConversionSettingsController::connectMinScaleValueSpinBox(QSpinBox *widget) {
    _minScaleValueSpinBox = widget;
    _minScaleValueSpinBox->setValue(_conversionSettingsModel->getMinScaleValue());
    refreshMinScaleValueSpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _conversionSettingsModel, &ConversionSettingsModel::setMinScaleValue);
    connect(_conversionSettingsModel, &ConversionSettingsModel::minScaleValueChanged, widget, &QSpinBox::setValue);
}

void ConversionSettingsController::connectXRatioSpinBox(QSpinBox *widget) {
    _xRatioSpinBox = widget;
    _xRatioSpinBox->setValue(_conversionSettingsModel->getXRatio());
    refreshXRatioSpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _conversionSettingsModel, &ConversionSettingsModel::setXRatio);
    connect(_conversionSettingsModel, &ConversionSettingsModel::xRatioChanged, widget, &QSpinBox::setValue);
}

void ConversionSettingsController::connectYRatioSpinBox(QSpinBox *widget) {
    _yRatioSpinBox = widget;
    _yRatioSpinBox->setValue(_conversionSettingsModel->getYRatio());
    refreshYRatioSpinBox();

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


void ConversionSettingsController::connectTextSizeSpinBox(QSpinBox *widget) {
    _textSizeSpinBox = widget;
    _textSizeSpinBox->setValue(_conversionSettingsModel->getTextSize());
    refreshTextSizeSpinBox();

    connect(widget, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), _conversionSettingsModel, &ConversionSettingsModel::setTextSize);
    connect(_conversionSettingsModel, &ConversionSettingsModel::textSizeChanged, widget, &QSpinBox::setValue);
}

void ConversionSettingsController::connectTextSizeSlider(QSlider *widget) {
    _textSizeSlider = widget;
    _textSizeSlider->setValue(_conversionSettingsModel->getTextSize());
    refreshTextSizeSlider();

    connect(widget, &QSlider::valueChanged, _conversionSettingsModel, &ConversionSettingsModel::setTextSize);
    connect(_conversionSettingsModel, &ConversionSettingsModel::textSizeChanged, widget, &QSlider::setValue);
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


void ConversionSettingsController::connectClearColorCheckBox(QCheckBox *widget) {
    _clearColorCheckBox = widget;
    _clearColorCheckBox->setChecked(_conversionSettingsModel->isClearColor());
    refreshClearColorCheckBox();

    connect(widget, &QCheckBox::toggled, _conversionSettingsModel, &ConversionSettingsModel::setClearColor);
    connect(_conversionSettingsModel, &ConversionSettingsModel::clearColorChanged, widget, &QCheckBox::setChecked);
}


void ConversionSettingsController::connectBackgroundColorView(QGraphicsView *widget) {
    _backgroundColorView = widget;
    setBackgroundColorViewColor(_conversionSettingsModel->getBackgroundColor());

    connect(_conversionSettingsModel, &ConversionSettingsModel::backgroundColorChanged, this, &ConversionSettingsController::setBackgroundColorViewColor);
}

void ConversionSettingsController::connectBackgroundColorButton(QPushButton *widget) {
    _backgroundColorButton = widget;
    refreshBackgroundColorButton();

    connect(widget, &QPushButton::clicked, this, &ConversionSettingsController::selectBackgroundColor);
}


void ConversionSettingsController::connectTextColorView(QGraphicsView *widget) {
    _textColorView = widget;
    setTextColorViewColor(_conversionSettingsModel->getTextColor());

    connect(_conversionSettingsModel, &ConversionSettingsModel::textColorChanged, this, &ConversionSettingsController::setTextColorViewColor);
}

void ConversionSettingsController::connectTextColorButton(QPushButton *widget) {
    _textColorButton = widget;
    refreshTextColorButton();

    connect(widget, &QPushButton::clicked, this, &ConversionSettingsController::selectTextColor);
}

void ConversionSettingsController::connectTextFontLineEdit(QLineEdit *widget) {
    _textFontLineEdit = widget;
    _textFontLineEdit->setEnabled(false);
    setTextFontLineEditFont(_conversionSettingsModel->getTextFont());

    connect(_conversionSettingsModel, &ConversionSettingsModel::textFontChanged, this, &ConversionSettingsController::setTextFontLineEditFont);
}

void ConversionSettingsController::connectTextFontButton(QPushButton *widget) {
    _textFontButton = widget;
    refreshTextFontButton();

    connect(widget, &QPushButton::clicked, this, &ConversionSettingsController::selectTextFont);
}




void ConversionSettingsController::selectBackgroundColor() {
    QColorDialog dialog;

    int result = dialog.exec();

    if(result) {
        _conversionSettingsModel->setBackgroundColor(dialog.selectedColor());
    }
}

void ConversionSettingsController::setBackgroundColorViewColor(const QColor &color) {
    _backgroundColorView->setStyleSheet("QGraphicsView { background-color: " + color.name() + "; }");
}


void ConversionSettingsController::selectTextColor() {
    QColorDialog dialog;

    int result = dialog.exec();

    if(result) {
        _conversionSettingsModel->setTextColor(dialog.selectedColor());
    }
}

void ConversionSettingsController::setTextColorViewColor(const QColor &color) {
    _textColorView->setStyleSheet("QGraphicsView { background-color: " + color.name() + "; }");
}

void ConversionSettingsController::selectTextFont() {
    QFontDialog dialog;

    int result = dialog.exec();

    if(result) {
        _conversionSettingsModel->setTextFont(dialog.selectedFont());
    }
}

void ConversionSettingsController::setTextFontLineEditFont(const QFont &textFont) {
    _textFontLineEdit->setFont(textFont);
    _textFontLineEdit->setText(textFont.family());
}



void ConversionSettingsController::refreshWidgets() {
    refreshConverterTypeComboBox();

    refreshHorizontalAlignmentComboBox();
    refreshVerticalAlignmentComboBox();

    refreshMaxScaleStrategyComboBox();
    refreshMaxScaleValueSpinBox();

    refreshMinScaleStrategyComboBox();
    refreshMinScaleValueSpinBox();

    refreshXRatioSpinBox();
    refreshYRatioSpinBox();

    refreshMarginSpinBox();
    refreshMarginSlider();

    refreshTextSizeSpinBox();
    refreshTextSizeSlider();

    refreshAlphaToleranceSpinBox();
    refreshAlphaToleranceSlider();

    refreshColorToleranceSpinBox();
    refreshColorToleranceSlider();

    refreshClearColorCheckBox();

    refreshBackgroundColorView();
    refreshBackgroundColorButton();

    refreshTextColorView();
    refreshTextColorButton();

    refreshTextFontLineEdit();
    refreshTextFontButton();
}

void ConversionSettingsController::refreshConverterTypeComboBox() {
    _converterTypeComboBox->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshHorizontalAlignmentComboBox() {
    _horizontalAlignmentComboBox->setEnabled(!_conversionModel->isRunning() &&
                                             _conversionSettingsModel->getConverterType() == ConversionSettingsModel::CropImageConverter);
}

void ConversionSettingsController::refreshVerticalAlignmentComboBox() {
    _verticalAlignmentComboBox->setEnabled(!_conversionModel->isRunning() &&
                                           _conversionSettingsModel->getConverterType() != ConversionSettingsModel::SquareImageConverter &&
                                           _conversionSettingsModel->getConverterType() != ConversionSettingsModel::ScaleImageConverter);
}

void ConversionSettingsController::refreshMaxScaleStrategyComboBox() {
    _maxScaleStrategyComboBox->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshMaxScaleValueSpinBox() {
    _maxScaleValueSpinBox->setEnabled(!_conversionModel->isRunning() &&
                                      _conversionSettingsModel->getMaxScaleStrategy() != ConversionSettingsModel::MaxScaleNone);
}

void ConversionSettingsController::refreshMinScaleStrategyComboBox() {
    _minScaleStrategyComboBox->setEnabled(!_conversionModel->isRunning());
}

void ConversionSettingsController::refreshMinScaleValueSpinBox() {
    _minScaleValueSpinBox->setEnabled(!_conversionModel->isRunning() &&
                                      _conversionSettingsModel->getMinScaleStrategy() != ConversionSettingsModel::MinScaleNone);
}

void ConversionSettingsController::refreshXRatioSpinBox() {
    _xRatioSpinBox->setEnabled(!_conversionModel->isRunning() &&
                               _conversionSettingsModel->getConverterType() != ConversionSettingsModel::TextImageConverter &&
                               _conversionSettingsModel->getConverterType() != ConversionSettingsModel::ScaleImageConverter);
}

void ConversionSettingsController::refreshYRatioSpinBox() {
    _yRatioSpinBox->setEnabled(!_conversionModel->isRunning() &&
                               _conversionSettingsModel->getConverterType() != ConversionSettingsModel::TextImageConverter &&
                               _conversionSettingsModel->getConverterType() != ConversionSettingsModel::ScaleImageConverter);
}


void ConversionSettingsController::refreshMarginSpinBox() {
    _marginSpinBox->setEnabled(!_conversionModel->isRunning() &&
                               _conversionSettingsModel->getConverterType() == ConversionSettingsModel::SquareImageConverter);
}

void ConversionSettingsController::refreshMarginSlider() {
    _marginSlider->setEnabled(!_conversionModel->isRunning() &&
                              _conversionSettingsModel->getConverterType() == ConversionSettingsModel::SquareImageConverter);
}


void ConversionSettingsController::refreshTextSizeSpinBox() {
    _textSizeSpinBox->setEnabled(!_conversionModel->isRunning() &&
                                 _conversionSettingsModel->getConverterType() == ConversionSettingsModel::TextImageConverter);
}

void ConversionSettingsController::refreshTextSizeSlider() {
    _textSizeSlider->setEnabled(!_conversionModel->isRunning() &&
                                _conversionSettingsModel->getConverterType() == ConversionSettingsModel::TextImageConverter);
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


void ConversionSettingsController::refreshClearColorCheckBox() {
    _clearColorCheckBox->setEnabled(!_conversionModel->isRunning());
}


void ConversionSettingsController::refreshBackgroundColorView() {
}

void ConversionSettingsController::refreshBackgroundColorButton() {
    _backgroundColorButton->setEnabled(!_conversionModel->isRunning());
}


void ConversionSettingsController::refreshTextColorView() {
}

void ConversionSettingsController::refreshTextColorButton() {
    _textColorButton->setEnabled(!_conversionModel->isRunning() &&
                                 _conversionSettingsModel->getConverterType() == ConversionSettingsModel::TextImageConverter);
}


void ConversionSettingsController::refreshTextFontLineEdit() {
}

void ConversionSettingsController::refreshTextFontButton() {
    _textFontButton->setEnabled(!_conversionModel->isRunning() &&
                                _conversionSettingsModel->getConverterType() == ConversionSettingsModel::TextImageConverter);
}
