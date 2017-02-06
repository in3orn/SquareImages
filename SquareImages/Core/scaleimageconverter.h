#ifndef SCALEIMAGECONVERTER_H
#define SCALEIMAGECONVERTER_H


#include "imageconverter.h"

#include "Model/conversionsettingsmodel.h"
#include "Model/mainsettingsmodel.h"

class ScaleImageConverter : public ImageConverter
{
public:
    ScaleImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

    virtual QImage convert(const QImage &source, const FileRecord &fileRecord) Q_DECL_OVERRIDE;

protected:
    virtual QImage createImage(const QImage &image) const;

    virtual QImage fillImage(const QImage &image, const QImage &source, const FileRecord &fileRecord) const;
    virtual QImage clearImage(const QImage &image) const;
    virtual QImage scaleImage(const QImage &image) const;


    virtual QSize getNewImageSize(const QSize &size) const;

    virtual bool isBackgroundColor(const QColor &color) const;

protected:
    ConversionSettingsModel &_conversionSettingsModel;
    MainSettingsModel &_fileSettingsModel;
};

#endif // SCALEIMAGECONVERTER_H
