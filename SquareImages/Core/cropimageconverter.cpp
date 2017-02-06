#include "cropimageconverter.h"

#include "imageutils.h"

CropImageConverter::CropImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    ScaleImageConverter(conversionSettingsModel, fileSettingsModel)
{

}



QImage CropImageConverter::fillImage(const QImage &image, const QImage &source, const FileRecord &/* fileRecord */) const
{
    QImage result(image);

    QPoint topLeft = getTopLeft(source, image.size());

    result = ImageUtils::insertCroppedImage(result, source, topLeft);

    return result;
}

QSize CropImageConverter::getNewImageSize(const QSize &size) const {

    double ratio = (double)_conversionSettingsModel.getXRatio() / (double)_conversionSettingsModel.getYRatio();

    if(ratio == 1.0) {
        int min = qMin(size.width(), size.height());
        return QSize(min, min);
    }

    QSize result(size);

    double height = result.width() / ratio;
    if(height <= result.height()) {
        result.setHeight(height);
    } else {
        double width = result.height() * ratio;
        result.setWidth(width);
    }

    return result;
}

QPoint CropImageConverter::getTopLeft(const QImage &image, const QSize &size) const
{
    int mx = 0;
    int my = 0;

    switch(_conversionSettingsModel.getHorizontalAlignment())
    {
    case ConversionSettingsModel::HCenter:
        mx = (image.size().width() - size.width()) / 2;
        break;
    case ConversionSettingsModel::Right:
        mx = (image.size().width() - size.width());
        break;
    }

    switch(_conversionSettingsModel.getVerticalAlignment())
    {
    case ConversionSettingsModel::VCenter:
        my = (image.size().height() - size.height()) / 2;
        break;
    case ConversionSettingsModel::Bottom:
        my = (image.size().height() - size.height());
        break;
    }

    return QPoint(mx, my);
}
