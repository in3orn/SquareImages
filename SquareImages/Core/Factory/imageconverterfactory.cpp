#include "imageconverterfactory.h"

#include "../squareimageconverter.h"

ImageConverterFactory &ImageConverterFactory::getInstance() {
    static ImageConverterFactory factory;
    return factory;
}

ImageConverter *ImageConverterFactory::createSquareImageConverter(
        ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) const {
    return new SquareImageConverter(conversionSettingsModel, fileSettingsModel);
}
