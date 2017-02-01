#include "midtextimageconverter.h"


MidTextImageConverter::MidTextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    TextImageConverter(conversionSettingsModel, fileSettingsModel)
{

}

QRect MidTextImageConverter::getTextRect(const QSize &imageSize, const QSize &rectSize) const
{
    QPoint topLeft(0, (imageSize.height() - rectSize.height())/2);
    return QRect(topLeft, rectSize);
}
