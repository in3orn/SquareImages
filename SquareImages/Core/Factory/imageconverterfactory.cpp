#include "imageconverterfactory.h"

#include "../cropimageconverter.h"

#include "../toptextimageconverter.h"
#include "../midtextimageconverter.h"
#include "../bottomtextimageconverter.h"

#include "../squareimageconverter.h"

ImageConverterFactory &ImageConverterFactory::getInstance() {
    static ImageConverterFactory factory;
    return factory;
}

ImageConverter *ImageConverterFactory::create(
        ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) const
{
    switch(conversionSettingsModel.getConverterType())
    {
    case ConversionSettingsModel::CropImageConverter:
        return new CropImageConverter(conversionSettingsModel, fileSettingsModel);
    case ConversionSettingsModel::TextImageConverter:
        return createTextImageConverter(conversionSettingsModel, fileSettingsModel);
    default:
        return new SquareImageConverter(conversionSettingsModel, fileSettingsModel);
    }
}

ImageConverter *ImageConverterFactory::createTextImageConverter(
        ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) const
{
    switch(conversionSettingsModel.getVerticalAlignment())
    {
    case ConversionSettingsModel::Top:
        return new TopTextImageConverter(conversionSettingsModel, fileSettingsModel);
    case ConversionSettingsModel::VCenter:
        return new MidTextImageConverter(conversionSettingsModel, fileSettingsModel);
    default:
        return new BottomTextImageConverter(conversionSettingsModel, fileSettingsModel);
    }
}
