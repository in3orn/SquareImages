#ifndef MIDTEXTIMAGECONVERTER_H
#define MIDTEXTIMAGECONVERTER_H


#include "textimageconverter.h"

class MidTextImageConverter : public TextImageConverter
{
public:
    MidTextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

protected:
    virtual QRect getTextRect(const QSize &imageSize, const QSize &rectSize) const Q_DECL_OVERRIDE;
};

#endif // MIDTEXTIMAGECONVERTER_H
