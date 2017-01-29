#ifndef IMAGECONVERTERFACTORY_H
#define IMAGECONVERTERFACTORY_H

#include "../imageconverter.h"

#include "Model/conversionsettingsmodel.h"
#include "Model/mainsettingsmodel.h"

class ImageConverterFactory
{
public:
    static ImageConverterFactory &getInstance();

public:
    ImageConverter *createSquareImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) const;
};

#endif // IMAGECONVERTERFACTORY_H
