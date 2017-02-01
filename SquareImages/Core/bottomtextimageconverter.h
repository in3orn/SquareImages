#ifndef BOTTOMTEXTIMAGECONVERTER_H
#define BOTTOMTEXTIMAGECONVERTER_H


#include "textimageconverter.h"

class BottomTextImageConverter : public TextImageConverter
{
public:
    BottomTextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

protected:
    virtual QRect getTextRect(const QSize &imageSize, const QSize &rectSize) const Q_DECL_OVERRIDE;

    virtual QSize getNewImageSize(const QSize &imageSize, const QSize &rectSize) const Q_DECL_OVERRIDE;
};

#endif // BOTTOMTEXTIMAGECONVERTER_H
