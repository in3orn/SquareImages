#include "conversionsettingsmodel.h"

ConversionSettingsModel::ConversionSettingsModel(QObject *parent) : QObject(parent),

    _xRatio(1),
    _yRatio(1),

    _margin(10),

    _alphaTolerance(10),
    _colorTolerance(10),

    _color("white"),

    _clearColor(false)
{

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

int ConversionSettingsModel::getAlphaTolerance() const {
    return _alphaTolerance;
}

int ConversionSettingsModel::getColorTolerance() const {
    return _colorTolerance;
}

QColor ConversionSettingsModel::getColor() const {
    return _color;
}

bool ConversionSettingsModel::isClearColor() const {
    return _clearColor;
}



void ConversionSettingsModel::setXRatio(int xRatio) {
    if(_xRatio != xRatio) {
        _xRatio = xRatio;
        xRatioChanged(_xRatio);
    }
}

void ConversionSettingsModel::setYRatio(int yRatio) {
    if(_yRatio != yRatio) {
        _yRatio = yRatio;
        yRatioChanged(_yRatio);
    }
}

void ConversionSettingsModel::setMargin(int margin) {
    if(_margin != margin) {
        _margin = margin;
        marginChanged(_margin);
    }
}

void ConversionSettingsModel::setAlphaTolerance(int alphaTolerance) {
    if(_alphaTolerance != alphaTolerance) {
        _alphaTolerance = alphaTolerance;
        alphaToleranceChanged(_alphaTolerance);
    }
}

void ConversionSettingsModel::setColorTolerance(int colorTolerance) {
    if(_colorTolerance != colorTolerance) {
        _colorTolerance = colorTolerance;
        colorToleranceChanged(_colorTolerance);
    }
}

void ConversionSettingsModel::setColor(const QColor &color) {
    if(_color != color) {
        _color = color;
        colorChanged(_color);
    }
}

void ConversionSettingsModel::setClearColor(bool clearColor) {
    if(_clearColor != clearColor) {
        _clearColor = clearColor;
        clearColorChanged(_clearColor);
    }
}
