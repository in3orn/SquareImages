#ifndef TEXTIMAGECONVERTER_H
#define TEXTIMAGECONVERTER_H


#include "imageconverter.h"

#include "Model/conversionsettingsmodel.h"
#include "Model/mainsettingsmodel.h"

#include "painttextsettings.h"

class TextImageConverter : public ImageConverter
{
public:
    TextImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

    virtual QImage convert(const QImage &image, const FileRecord &fileRecord) Q_DECL_OVERRIDE;

protected:
    virtual QSize getTextRectSize(const QSize &size) const;

    virtual QRect getTextRect(const QSize &imageSize, const QSize &rectSize) const;

    virtual QSize getNewImageSize(const QSize &imageSize, const QSize &rectSize) const;

    virtual QPoint getImageTopLeft(const QSize &imageSize, const QSize &rectSize) const;

    virtual int getTextFontHeight(int rectHeight) const;

protected:
    ConversionSettingsModel &_conversionSettingsModel;
    MainSettingsModel &_fileSettingsModel;

    PaintTextSettings _paintTextSettings;
};

#endif // TEXTIMAGECONVERTER_H
