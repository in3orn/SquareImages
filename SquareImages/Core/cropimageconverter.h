#ifndef CROPIMAGECONVERTER_H
#define CROPIMAGECONVERTER_H

#include "imageconverter.h"

#include "Model/conversionsettingsmodel.h"
#include "Model/mainsettingsmodel.h"

class CropImageConverter : public ImageConverter
{
public:
    CropImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

    virtual QImage convert(const QImage &image, const FileRecord &fileRecord) Q_DECL_OVERRIDE;

protected:
    QSize getNewImageSize(const QSize &size) const;

    QPoint getTopLeft(const QImage &image, const QSize &size) const;

protected:
    ConversionSettingsModel &_conversionSettingsModel;
    MainSettingsModel &_fileSettingsModel;
};

#endif // CROPIMAGECONVERTER_H
