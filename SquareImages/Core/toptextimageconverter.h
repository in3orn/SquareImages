#ifndef TOPTEXTIMAGECONVERTER_H
#define TOPTEXTIMAGECONVERTER_H

#include "textimageconverter.h"

class TopTextImageConverter : public TextImageConverter
{
public:
    TopTextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

protected:
    virtual QSize getNewImageSize(const QSize &imageSize, const QSize &rectSize) const Q_DECL_OVERRIDE;

    virtual QPoint getImageTopLeft(const QSize &imageSize, const QSize &rectSize) const Q_DECL_OVERRIDE;
};

#endif // TOPTEXTIMAGECONVERTER_H
