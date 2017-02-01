#include "cropimageconverter.h"

#include "imageutils.h"

CropImageConverter::CropImageConverter(ConversionSettingsModel &conversionSettingsModel, MainSettingsModel &fileSettingsModel) :
    _conversionSettingsModel(conversionSettingsModel),
    _fileSettingsModel(fileSettingsModel)
{

}



QImage CropImageConverter::convert(const QImage &image, const FileRecord &/* fileRecord */)
{
    QImage::Format format = ImageUtils::getOutputFormat(_fileSettingsModel.getForcedFormat(), image.format());
    QSize size = getNewImageSize(image.size());

    QImage newImage(size, format);

    QPoint topLeft = getTopLeft(image, size);
    newImage = ImageUtils::insertCroppedImage(newImage, image, topLeft);
    if(_conversionSettingsModel.isClearColor()) {
        newImage = ImageUtils::removeColor(newImage,
                                           _conversionSettingsModel.getBackgroundColor(),
                                           _conversionSettingsModel.getColorTolerance(),
                                           _conversionSettingsModel.getAlphaTolerance());
    }

    return newImage;
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
