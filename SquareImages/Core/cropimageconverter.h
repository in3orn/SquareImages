#ifndef CROPIMAGECONVERTER_H
#define CROPIMAGECONVERTER_H

#include "scaleimageconverter.h"

class CropImageConverter : public ScaleImageConverter
{
public:
    CropImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

protected:
    virtual QImage fillImage(const QImage &image, const QImage &source, const FileRecord &fileRecord) const Q_DECL_OVERRIDE;

    virtual QSize getNewImageSize(const QSize &size) const Q_DECL_OVERRIDE;

    QPoint getTopLeft(const QImage &image, const QSize &size) const;
};

#endif // CROPIMAGECONVERTER_H
