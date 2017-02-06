#ifndef SQUAREIMAGECONVERTER_H
#define SQUAREIMAGECONVERTER_H

#include "scaleimageconverter.h"

class SquareImageConverter : public ScaleImageConverter
{
public:
    SquareImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

    virtual QImage convert(const QImage &image, const FileRecord &fileRecord) Q_DECL_OVERRIDE;

protected:
    virtual QSize getNewImageSize(const QSize &size) const Q_DECL_OVERRIDE;

    int getTopMargin(const QImage &image) const;
    int getLeftMargin(const QImage &image) const;
    int getRightMargin(const QImage &image) const;
    int getBottomMargin(const QImage &image) const;
};

#endif // SQUAREIMAGECONVERTER_H
