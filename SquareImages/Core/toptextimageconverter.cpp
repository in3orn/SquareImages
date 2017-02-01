#include "toptextimageconverter.h"

TopTextImageConverter::TopTextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    TextImageConverter(conversionSettingsModel, fileSettingsModel)
{

}

QSize TopTextImageConverter::getNewImageSize(const QSize &imageSize, const QSize &rectSize) const
{
    return QSize(imageSize.width(), imageSize.height() + rectSize.height());
}

QPoint TopTextImageConverter::getImageTopLeft(const QSize &/* imageSize */, const QSize &rectSize) const
{
    return QPoint(0, rectSize.height());
}
