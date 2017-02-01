#include "bottomtextimageconverter.h"


BottomTextImageConverter::BottomTextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    TextImageConverter(conversionSettingsModel, fileSettingsModel)
{

}

QRect BottomTextImageConverter::getTextRect(const QSize &imageSize, const QSize &rectSize) const
{
    QPoint topLeft(0, imageSize.height() - rectSize.height());
    return QRect(topLeft, rectSize);
}

QSize BottomTextImageConverter::getNewImageSize(const QSize &imageSize, const QSize &rectSize) const
{
    return QSize(imageSize.width(), imageSize.height() + rectSize.height());
}
