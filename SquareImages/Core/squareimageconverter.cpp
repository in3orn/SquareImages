#include "squareimageconverter.h"

#include "imageutils.h"

SquareImageConverter::SquareImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    ScaleImageConverter(conversionSettingsModel, fileSettingsModel)
{

}



QImage SquareImageConverter::convert(const QImage &source, const FileRecord &/* fileRecord */) {

    int topMargin = getTopMargin(source);
    int leftMargin = getLeftMargin(source);
    int rightMargin = getRightMargin(source);
    int bottomMargin = getBottomMargin(source);

    int width = source.width() - leftMargin - rightMargin;
    int height = source.height() - topMargin - bottomMargin;

    int margin = qMin(width, height) * _conversionSettingsModel.getMargin() / 100;

    QSize size = getNewImageSize(QSize(width + 2*margin, height + 2*margin));

    QImage::Format format = ImageUtils::getOutputFormat(_fileSettingsModel.getForcedFormat(), source.format());
    QImage image(size, format);

    QColor bkgColor = ImageUtils::getBackgroundColor(format);
    image.fill(bkgColor);

    int mx = (size.width() - width) / 2;
    int my = (size.height() - height) / 2;

    QPoint topLeft(mx, my);

    QPoint regionLeft(leftMargin, topMargin);
    QSize regionSize(width, height);
    QRect region(regionLeft, regionSize);

    image = ImageUtils::insertImageRegion(image, source, region, topLeft);

    image = clearImage(image);
    image = scaleImage(image);

    return image;
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

int SquareImageConverter::getTopMargin(const QImage &image) const {

    int margin = image.height();

    for(int x = 0; x < image.width(); x++) {

        int currentMargin = 0;

        for(int y = 0; y < image.height(); y++) {
            QColor color = image.pixelColor(x, y);
            if(!isBackgroundColor(color)) break;
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
            if(!isBackgroundColor(color)) break;
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
            if(!isBackgroundColor(color)) break;
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
            if(!isBackgroundColor(color)) break;
            currentMargin++;
        }

        if(currentMargin < margin) {
            margin = currentMargin;
        }
    }

    return margin;
}
