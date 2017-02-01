#include "squareimageconverter.h"

#include "imageutils.h"

SquareImageConverter::SquareImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    _conversionSettingsModel(conversionSettingsModel),
    _fileSettingsModel(fileSettingsModel),
    _transparent("transparent"),
    _white("white")
{

}



QImage SquareImageConverter::convert(const QImage &image, const FileRecord &/* fileRecord */) {

    int topMargin = getTopMargin(image);
    int leftMargin = getLeftMargin(image);
    int rightMargin = getRightMargin(image);
    int bottomMargin = getBottomMargin(image);

    int width = image.width() - leftMargin - rightMargin;
    int height = image.height() - topMargin - bottomMargin;

    int margin = qMin(width, height) * _conversionSettingsModel.getMargin() / 100;

    QSize size = getNewImageSize(QSize(width + 2*margin, height + 2*margin));

    QImage::Format format = ImageUtils::getOutputFormat(_fileSettingsModel.getForcedFormat(), image.format());
    QImage newImage(size, format);

    QColor bkgColor = ImageUtils::getBackgroundColor(format);
    newImage.fill(bkgColor);

    int mx = (size.width() - width) / 2;
    int my = (size.height() - height) / 2;

    QPoint topLeft(mx, my);

    QPoint regionLeft(leftMargin, topMargin);
    QSize regionSize(width, height);
    QRect region(regionLeft, regionSize);

    newImage = ImageUtils::insertImageRegion(newImage, image, region, topLeft);
    if(_conversionSettingsModel.isClearColor()) {
        newImage = ImageUtils::removeColor(newImage,
                                           _conversionSettingsModel.getBackgroundColor(),
                                           _conversionSettingsModel.getColorTolerance(),
                                           _conversionSettingsModel.getAlphaTolerance());
    }

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

QSize SquareImageConverter::getNewImageSize(const QSize &size) const {

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

    QColor bkgColor = _conversionSettingsModel.getBackgroundColor();
    int colorTolerance = _conversionSettingsModel.getColorTolerance();

    if(qAbs(bkgColor.red() - color.red()) > colorTolerance) return false;
    if(qAbs(bkgColor.green() - color.green()) > colorTolerance) return false;
    if(qAbs(bkgColor.blue() - color.blue()) > colorTolerance) return false;

    return true;
}
