#ifndef TEXTIMAGECONVERTER_H
#define TEXTIMAGECONVERTER_H


#include "scaleimageconverter.h"

#include "painttextsettings.h"

class TextImageConverter : public ScaleImageConverter
{
public:
    TextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

    virtual QImage convert(const QImage &source, const FileRecord &fileRecord) Q_DECL_OVERRIDE;

protected:
    virtual QSize getTextRectSize(const QSize &size) const;

    virtual QRect getTextRect(const QSize &imageSize, const QSize &rectSize) const;

    virtual QSize getNewImageSize(const QSize &imageSize, const QSize &rectSize) const;

    virtual QPoint getImageTopLeft(const QSize &imageSize, const QSize &rectSize) const;

    virtual int getTextFontHeight(int rectHeight) const;

protected:
    PaintTextSettings _paintTextSettings;
};

#endif // TEXTIMAGECONVERTER_H
