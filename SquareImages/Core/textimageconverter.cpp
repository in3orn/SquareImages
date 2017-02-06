#include "textimageconverter.h"

#include <QPainter>

#include "imageutils.h"

TextImageConverter::TextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    ScaleImageConverter(conversionSettingsModel, fileSettingsModel)
{
    _paintTextSettings.pen = QPen(_conversionSettingsModel.getTextColor());
    _paintTextSettings.font = _conversionSettingsModel.getTextFont();
    _paintTextSettings.alignment = Qt::AlignCenter;
}



QImage TextImageConverter::convert(const QImage &source, const FileRecord &fileRecord)
{
    QImage::Format format = ImageUtils::getOutputFormat(_fileSettingsModel.getForcedFormat(), source.format());
    QColor backgroundColor = ImageUtils::getBackgroundColor(format);

    QSize rectSize = getTextRectSize(source.size());
    QSize newSize = getNewImageSize(source.size(), rectSize);

    QImage image(newSize, format);
    image.fill(backgroundColor);

    QPoint topLeft = getImageTopLeft(newSize, rectSize);
    image = ImageUtils::insertImage(image, source, topLeft);

    image = clearImage(image);

    _paintTextSettings.font.setPixelSize(getTextFontHeight(rectSize.height()));
    _paintTextSettings.rect = getTextRect(newSize, rectSize);
    image = ImageUtils::insertText(image, _paintTextSettings, fileRecord.name);

    image = scaleImage(image);

    return image;
}

QSize TextImageConverter::getTextRectSize(const QSize &size) const
{
    return QSize(size.width(), size.width() * _conversionSettingsModel.getTextSize() / 100);
}

QRect TextImageConverter::getTextRect(const QSize &/* imageSize */, const QSize &rectSize) const
{
    return QRect(QPoint(), rectSize);
}

QSize TextImageConverter::getNewImageSize(const QSize &imageSize, const QSize &/* rectSize */) const
{
    return imageSize;
}

QPoint TextImageConverter::getImageTopLeft(const QSize &/* imageSize */, const QSize &/* rectSize */) const
{
    return QPoint();
}

int TextImageConverter::getTextFontHeight(int rectHeight) const {
    return rectHeight / 2;
}
