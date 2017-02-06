#ifndef IMAGEUTILS_H
#define IMAGEUTILS_H

#include <QImage>

#include "Model/mainsettingsmodel.h"
#include "Model/conversionsettingsmodel.h"

#include "painttextsettings.h"

class ImageUtils
{
public:
    static QImage insertImage(const QImage &image, const QImage &inserted);

    static QImage insertImage(const QImage &image, const QImage &inserted, const QPoint &topLeft);

    static QImage insertImageRegion(const QImage &image, const QImage &inserted, const QRect &region, const QPoint &topLeft);

    static QImage insertCroppedImage(const QImage &image, const QImage &inserted, const QPoint &topLeft = QPoint());

    static QImage insertText(const QImage &image, const PaintTextSettings &settings, const QString &text);

    static QImage removeColor(const QImage &image, const QColor &color, int colorTolerance = 0, int alphaTolerance = 0);

    static QImage getMaxScaledImage(const QImage &image, ConversionSettingsModel::MaxScaleStrategy strategy, int maxValue);

    static QImage getMinScaledImage(const QImage &image, ConversionSettingsModel::MinScaleStrategy strategy, int minValue);

    static QImage::Format getOutputFormat(MainSettingsModel::ForcedFormat forcedFormat, QImage::Format defaultFormat);

    static QColor getBackgroundColor(QImage::Format format);

    static bool hasAlpha(QImage::Format format);

    static bool isBackgroundColor(const QColor &color, const QColor &backgroundColor, int colorTolerance, int alphaTolerance);
};

#endif // IMAGEUTILS_H
