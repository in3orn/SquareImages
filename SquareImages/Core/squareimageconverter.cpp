#include "squareimageconverter.h"

#include "colorutils.h"

#include <QPainter>

SquareImageConverter::SquareImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    _conversionSettingsModel(conversionSettingsModel),
    _fileSettingsModel(fileSettingsModel),
    _transparent("transparent"),
    _white("white")
{

}



QImage SquareImageConverter::convert(const QImage &image) const {

    int topMargin = getTopMargin(image);
    int leftMargin = getLeftMargin(image);
    int rightMargin = getRightMargin(image);
    int bottomMargin = getBottomMargin(image);

    int width = image.width() - leftMargin - rightMargin;
    int height = image.height() - topMargin - bottomMargin;

    int margin = qMin(width, height) * _conversionSettingsModel.getMargin() / 100;

    QSize size = getNewSize(QSize(width + 2*margin, height + 2*margin));

    int mx = (size.width() - width) / 2;
    int my = (size.height() - height) / 2;

    QColor bkgColor = _white;
    QImage::Format format = QImage::Format_RGB888;

    if(_fileSettingsModel.getForcedFormat() == MainSettingsModel::ForcedFormat::PNG) {
        bkgColor = _transparent;
        format = QImage::Format_RGBA8888;
    } else if(_fileSettingsModel.getForcedFormat() == MainSettingsModel::ForcedFormat::None) {
        bkgColor = ColorUtils::hasAlpha(image.format()) ? _transparent : _white;
        format = image.format();
    }

    QImage newImage(size, format);

    for(int x = 0; x < size.width(); x++) {
        for(int y = 0; y < size.height(); y++) {
            newImage.setPixelColor(x, y, bkgColor);
        }
    }

    bool clearColor = _conversionSettingsModel.isClearColor();

    int imageX = leftMargin;
    for(int x = mx; x < size.width() - mx; x++) {

        int imageY = topMargin;
        for(int y = my; y < size.height() - my; y++) {
            QColor color = image.pixelColor(imageX, imageY);
            if(clearColor && isMarginColor(color)) {
                color = bkgColor;
            }

            newImage.setPixelColor(x, y, color);
            imageY++;
        }
        imageX++;
    }

//    QPainter painter(&newImage);
//    painter.setPen(QPen(Qt::blue));
//    painter.setFont(QFont("Arial Black", 64, QFont::Bold));
//    painter.drawText(newImage.rect(), Qt::AlignCenter, "Samsung");

    return newImage;
}

int SquareImageConverter::getTopMargin(const QImage &image) const {

    int margin = image.height();

    for(int x = 0; x < image.width(); x++) {

        int currentMargin = 0;

        for(int y = 0; y < image.height(); y++) {
            QColor color = image.pixelColor(x, y);
            if(!isMarginColor(color)) break;
            currentMargin++;
        }

        if(currentMargin < margin) {
            margin = currentMargin;
        }
    }

    return margin;
}

int SquareImageConverter::getLeftMargin(const QImage &image) const {

    int margin = image.width();

    for(int y = 0; y < image.height(); y++) {

        int currentMargin = 0;

        for(int x = 0; x < image.width(); x++) {
            QColor color = image.pixelColor(x, y);
            if(!isMarginColor(color)) break;
            currentMargin++;
        }

        if(currentMargin < margin) {
            margin = currentMargin;
        }
    }

    return margin;
}

int SquareImageConverter::getRightMargin(const QImage &image) const {

    int margin = image.width();

    for(int y = 0; y < image.height(); y++) {

        int currentMargin = 0;

        for(int x = image.width()-1; x > -1; x--) {
            QColor color = image.pixelColor(x, y);
            if(!isMarginColor(color)) break;
            currentMargin++;
        }

        if(currentMargin < margin) {
            margin = currentMargin;
        }
    }

    return margin;
}

int SquareImageConverter::getBottomMargin(const QImage &image) const {

    int margin = image.height();

    for(int x = 0; x < image.width(); x++) {

        int currentMargin = 0;

        for(int y = image.height()-1; y > -1; y--) {
            QColor color = image.pixelColor(x, y);
            if(!isMarginColor(color)) break;
            currentMargin++;
        }

        if(currentMargin < margin) {
            margin = currentMargin;
        }
    }

    return margin;
}

QSize SquareImageConverter::getNewSize(const QSize &size) const {

    double ratio = (double)_conversionSettingsModel.getXRatio() / (double)_conversionSettingsModel.getYRatio();

    if(ratio == 1.0) {
        int max = qMax(size.width(), size.height());
        return QSize(max, max);
    }

    QSize result(size);

    if(ratio > 1) {
        result.setWidth(result.height() * ratio);
        if(result.width() < size.width()) {
            result.setWidth(size.width());
            result.setHeight(result.width() / ratio);
        }
    }
    else if(ratio < 1) {
        result.setHeight(result.width() / ratio);
        if(result.height() < size.height()) {
            result.setHeight(size.height());
            result.setWidth(result.height() * ratio);
        }
    }

    return result;
}

bool SquareImageConverter::isMarginColor(const QColor &color) const {
    if(color.alpha() < _conversionSettingsModel.getAlphaTolerance()) return true;

    QColor bkgColor = _conversionSettingsModel.getColor();
    int colorTolerance = _conversionSettingsModel.getColorTolerance();

    if(qAbs(bkgColor.red() - color.red()) > colorTolerance) return false;
    if(qAbs(bkgColor.green() - color.green()) > colorTolerance) return false;
    if(qAbs(bkgColor.blue() - color.blue()) > colorTolerance) return false;

    return true;
}
