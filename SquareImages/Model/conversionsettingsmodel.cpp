#include "conversionsettingsmodel.h"

QStringList ConversionSettingsModel::initConverterTypeNames()
{
    QStringList names;

    names << tr("Powiększający");
    names << tr("Kadrujący");
    names << tr("Tekstowy");
    names << tr("Skalujący");

    return names;
}

QStringList ConversionSettingsModel::converterTypeNames = ConversionSettingsModel::initConverterTypeNames();

QStringList ConversionSettingsModel::initHorizontalAlignmentNames()
{
    QStringList names;

    names << tr("Do lewej");
    names << tr("Do środka");
    names << tr("Do prawej");

    return names;
}

QStringList ConversionSettingsModel::horizontalAlignmentNames = ConversionSettingsModel::initHorizontalAlignmentNames();

QStringList ConversionSettingsModel::initVerticalAlignmentNames()
{
    QStringList names;

    names << tr("Do góry");
    names << tr("Do środka");
    names << tr("Do dołu");

    return names;
}

QStringList ConversionSettingsModel::verticalAlignmentNames = ConversionSettingsModel::initVerticalAlignmentNames();

QStringList ConversionSettingsModel::initMaxScaleStrategyNames()
{
    QStringList names;

    names << tr("Brak");
    names << tr("Szerokość");
    names << tr("Wysokość");

    return names;
}

QStringList ConversionSettingsModel::maxScaleStrategyNames = ConversionSettingsModel::initMaxScaleStrategyNames();

QStringList ConversionSettingsModel::initMinScaleStrategyNames()
{
    QStringList names;

    names << tr("Brak");
    names << tr("Szerokość");
    names << tr("Wysokość");

    return names;
}

QStringList ConversionSettingsModel::minScaleStrategyNames = ConversionSettingsModel::initMinScaleStrategyNames();



ConversionSettingsModel::ConversionSettingsModel(QObject *parent) : QObject(parent),
    _converterType(SquareImageConverter),

    _horizontalAlignment(Left),
    _verticalAlignment(Top),

    _maxScaleStrategy(MaxScaleNone),
    _minScaleStrategy(MinScaleNone),

    _xRatio(1),
    _yRatio(1),

    _margin(10),

    _textSize(20),

    _alphaTolerance(10),
    _colorTolerance(10),

    _maxScaleValue(600),
    _minScaleValue(600),

    _clearColor(false),

    _backgroundColor("white"),
    _textColor("black"),

    _textFont("Arial Black")
{

}



ConversionSettingsModel::ConverterType ConversionSettingsModel::getConverterType() const {
    return _converterType;
}

ConversionSettingsModel::HorizontalAlignment ConversionSettingsModel::getHorizontalAlignment() const {
    return _horizontalAlignment;
}

ConversionSettingsModel::VerticalAlignment ConversionSettingsModel::getVerticalAlignment() const {
    return _verticalAlignment;
}

ConversionSettingsModel::MaxScaleStrategy ConversionSettingsModel::getMaxScaleStrategy() const {
    return _maxScaleStrategy;
}

ConversionSettingsModel::MinScaleStrategy ConversionSettingsModel::getMinScaleStrategy() const {
    return _minScaleStrategy;
}

int ConversionSettingsModel::getXRatio() const {
    return _xRatio;
}

int ConversionSettingsModel::getYRatio() const {
    return _yRatio;
}

int ConversionSettingsModel::getMargin() const {
    return _margin;
}

int ConversionSettingsModel::getTextSize() const {
    return _textSize;
}

int ConversionSettingsModel::getAlphaTolerance() const {
    return _alphaTolerance;
}

int ConversionSettingsModel::getColorTolerance() const {
    return _colorTolerance;
}

int ConversionSettingsModel::getMaxScaleValue() const {
    return _maxScaleValue;
}

int ConversionSettingsModel::getMinScaleValue() const {
    return _minScaleValue;
}

bool ConversionSettingsModel::isClearColor() const {
    return _clearColor;
}

QColor ConversionSettingsModel::getBackgroundColor() const {
    return _backgroundColor;
}

QColor ConversionSettingsModel::getTextColor() const {
    return _textColor;
}

QFont ConversionSettingsModel::getTextFont() const {
    return _textFont;
}



void ConversionSettingsModel::setConverterType(ConverterType converterType) {
    if(_converterType != converterType) {
        _converterType = converterType;
        emit converterTypeChanged(static_cast<int>(_converterType));
        emit converterTypeChanged(_converterType);
    }
}

void ConversionSettingsModel::setConverterType(int converterType) {
    setConverterType(static_cast<ConverterType>(converterType));
}

void ConversionSettingsModel::setHorizontalAlignment(HorizontalAlignment horizontalAlignment) {
    if(_horizontalAlignment != horizontalAlignment) {
        _horizontalAlignment = horizontalAlignment;
        emit horizontalAlignmentChanged(static_cast<int>(_horizontalAlignment));
        emit horizontalAlignmentChanged(_horizontalAlignment);
    }
}

void ConversionSettingsModel::setHorizontalAlignment(int horizontalAlignment) {
    setHorizontalAlignment(static_cast<HorizontalAlignment>(horizontalAlignment));
}

void ConversionSettingsModel::setVerticalAlignment(VerticalAlignment verticalAlignment) {
    if(_verticalAlignment != verticalAlignment) {
        _verticalAlignment = verticalAlignment;
        emit verticalAlignmentChanged(static_cast<int>(_verticalAlignment));
        emit verticalAlignmentChanged(_verticalAlignment);
    }
}

void ConversionSettingsModel::setVerticalAlignment(int verticalAlignment) {
    setVerticalAlignment(static_cast<VerticalAlignment>(verticalAlignment));
}

void ConversionSettingsModel::setMaxScaleStrategy(MaxScaleStrategy maxScaleStrategy) {
    if(_maxScaleStrategy != maxScaleStrategy) {
        _maxScaleStrategy = maxScaleStrategy;
        emit maxScaleStrategyChanged(static_cast<int>(_maxScaleStrategy));
        emit maxScaleStrategyChanged(_maxScaleStrategy);
    }
}

void ConversionSettingsModel::setMaxScaleStrategy(int maxScaleStrategy) {
    setMaxScaleStrategy(static_cast<MaxScaleStrategy>(maxScaleStrategy));
}

void ConversionSettingsModel::setMinScaleStrategy(MinScaleStrategy minScaleStrategy) {
    if(_minScaleStrategy != minScaleStrategy) {
        _minScaleStrategy = minScaleStrategy;
        emit minScaleStrategyChanged(static_cast<int>(_minScaleStrategy));
        emit minScaleStrategyChanged(_minScaleStrategy);
    }
}

void ConversionSettingsModel::setMinScaleStrategy(int minScaleStrategy) {
    setMinScaleStrategy(static_cast<MinScaleStrategy>(minScaleStrategy));
}

void ConversionSettingsModel::setXRatio(int xRatio) {
    if(_xRatio != xRatio) {
        _xRatio = xRatio;
        emit xRatioChanged(_xRatio);
    }
}

void ConversionSettingsModel::setYRatio(int yRatio) {
    if(_yRatio != yRatio) {
        _yRatio = yRatio;
        emit yRatioChanged(_yRatio);
    }
}

void ConversionSettingsModel::setMargin(int margin) {
    if(_margin != margin) {
        _margin = margin;
        emit marginChanged(_margin);
    }
}

void ConversionSettingsModel::setTextSize(int textSize) {
    if(_textSize != textSize) {
        _textSize = textSize;
        emit textSizeChanged(_textSize);
    }
}

void ConversionSettingsModel::setAlphaTolerance(int alphaTolerance) {
    if(_alphaTolerance != alphaTolerance) {
        _alphaTolerance = alphaTolerance;
        emit alphaToleranceChanged(_alphaTolerance);
    }
}

void ConversionSettingsModel::setColorTolerance(int colorTolerance) {
    if(_colorTolerance != colorTolerance) {
        _colorTolerance = colorTolerance;
        emit colorToleranceChanged(_colorTolerance);
    }
}

void ConversionSettingsModel::setMaxScaleValue(int maxScaleValue) {
    if(_maxScaleValue != maxScaleValue) {
        _maxScaleValue = maxScaleValue;
        emit maxScaleValueChanged(_maxScaleValue);
    }
}

void ConversionSettingsModel::setMinScaleValue(int minScaleValue) {
    if(_minScaleValue != minScaleValue) {
        _minScaleValue = minScaleValue;
        emit minScaleValueChanged(_minScaleValue);
    }
}

void ConversionSettingsModel::setClearColor(bool clearColor) {
    if(_clearColor != clearColor) {
        _clearColor = clearColor;
        emit clearColorChanged(_clearColor);
    }
}

void ConversionSettingsModel::setBackgroundColor(const QColor &backgroundColor) {
    if(_backgroundColor != backgroundColor) {
        _backgroundColor = backgroundColor;
        emit backgroundColorChanged(_backgroundColor);
    }
}

void ConversionSettingsModel::setTextColor(const QColor &textColor) {
    if(_textColor != textColor) {
        _textColor = textColor;
        emit textColorChanged(_textColor);
    }
}

void ConversionSettingsModel::setTextFont(const QFont &textFont) {
    if(_textFont != textFont) {
        _textFont = textFont;
        emit textFontChanged(_textFont);
    }
}
