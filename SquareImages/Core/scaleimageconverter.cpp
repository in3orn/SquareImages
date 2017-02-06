#include "scaleimageconverter.h"

#include "imageutils.h"

ScaleImageConverter::ScaleImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    _conversionSettingsModel(conversionSettingsModel),
    _fileSettingsModel(fileSettingsModel)
{

}



QImage ScaleImageConverter::convert(const QImage &source, const FileRecord &fileRecord)
{
    QImage image = createImage(source);

    image = fillImage(image, source, fileRecord);
    image = clearImage(image);
    image = scaleImage(image);

    return image;
}



QImage ScaleImageConverter::createImage(const QImage &source) const
{
    QImage::Format format = ImageUtils::getOutputFormat(_fileSettingsModel.getForcedFormat(), source.format());
    QSize size = getNewImageSize(source.size());

    return QImage(size, format);
}


QImage ScaleImageConverter::fillImage(const QImage &image, const QImage &source, const FileRecord &/* fileRecord */) const
{
    return ImageUtils::insertImage(image, source);
}

QImage ScaleImageConverter::clearImage(const QImage &image) const
{
    QImage result(image);

    if(_conversionSettingsModel.isClearColor()) {
        result = ImageUtils::removeColor(result, _conversionSettingsModel.getBackgroundColor(),
                                         _conversionSettingsModel.getColorTolerance(),
                                         _conversionSettingsModel.getAlphaTolerance());
    }

    return result;
}

QImage ScaleImageConverter::scaleImage(const QImage &image) const
{
    QImage result(image);

    result = ImageUtils::getMaxScaledImage(result, _conversionSettingsModel.getMaxScaleStrategy(), _conversionSettingsModel.getMaxScaleValue());
    result = ImageUtils::getMinScaledImage(result, _conversionSettingsModel.getMinScaleStrategy(), _conversionSettingsModel.getMinScaleValue());

    return result;
}



QSize ScaleImageConverter::getNewImageSize(const QSize &size) const
{
    return size;
}

bool ScaleImageConverter::isBackgroundColor(const QColor &color) const {
    return ImageUtils::isBackgroundColor(color,
                                         _conversionSettingsModel.getBackgroundColor(),
                                         _conversionSettingsModel.getColorTolerance(),
                                         _conversionSettingsModel.getAlphaTolerance());
}
