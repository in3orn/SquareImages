#ifndef SQUAREIMAGECONVERTER_H
#define SQUAREIMAGECONVERTER_H

#include "imageconverter.h"

#include "Model/conversionsettingsmodel.h"
#include "Model/mainsettingsmodel.h"

class SquareImageConverter : public ImageConverter
{
public:
    SquareImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel);

    virtual QImage convert(const QImage &image, const FileRecord &fileRecord) Q_DECL_OVERRIDE;

protected:
    int getTopMargin(const QImage &image) const;
    int getLeftMargin(const QImage &image) const;
    int getRightMargin(const QImage &image) const;
    int getBottomMargin(const QImage &image) const;

    QSize getNewImageSize(const QSize &size) const;

    bool isMarginColor(const QColor &color) const;

protected:
    ConversionSettingsModel &_conversionSettingsModel;
    MainSettingsModel &_fileSettingsModel;

    QColor _transparent;
    QColor _white;
};

#endif // SQUAREIMAGECONVERTER_H
