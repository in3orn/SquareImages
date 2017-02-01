#include "textimageconverter.h"

#include <QPainter>

#include "imageutils.h"

TextImageConverter::TextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    _conversionSettingsModel(conversionSettingsModel),
    _fileSettingsModel(fileSettingsModel)
{
    _paintTextSettings.pen = QPen(_conversionSettingsModel.getTextColor());
    _paintTextSettings.font = _conversionSettingsModel.getTextFont();
    _paintTextSettings.alignment = Qt::AlignCenter;
}



QImage TextImageConverter::convert(const QImage &image, const FileRecord &fileRecord)
{
    QImage::Format format = ImageUtils::getOutputFormat(_fileSettingsModel.getForcedFormat(), image.format());
    QColor backgroundColor = ImageUtils::getBackgroundColor(format);

    QSize rectSize = getTextRectSize(image.size());
    QSize newSize = getNewImageSize(image.size(), rectSize);

    QImage newImage(newSize, format);
    newImage.fill(backgroundColor);

    QPoint topLeft = getImageTopLeft(newSize, rectSize);
    newImage = ImageUtils::insertImage(newImage, image, topLeft);
    if(_conversionSettingsModel.isClearColor()) {
        newImage = ImageUtils::removeColor(newImage,
                                           _conversionSettingsModel.getBackgroundColor(),
                                           _conversionSettingsModel.getColorTolerance(),
                                           _conversionSettingsModel.getAlphaTolerance());
    }

    _paintTextSettings.font.setPixelSize(getTextFontHeight(rectSize.height()));
    _paintTextSettings.rect = getTextRect(newSize, rectSize);
    newImage = ImageUtils::insertText(newImage, _paintTextSettings, fileRecord.name);

    return newImage;
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
