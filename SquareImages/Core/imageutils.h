#ifndef IMAGEUTILS_H
#define IMAGEUTILS_H

#include <QImage>

#include "Model/mainsettingsmodel.h"

#include "painttextsettings.h"

class ImageUtils
{
public:
    static QImage insertImage(QImage &image, const QImage &inserted, const QPoint &topLeft);

    static QImage insertImageRegion(QImage &image, const QImage &inserted, const QRect &region, const QPoint &topLeft);

    static QImage insertCroppedImage(QImage &image, const QImage &inserted, const QPoint &topLeft = QPoint());

    static QImage insertText(QImage &image, const PaintTextSettings &settings, const QString &text);

    static QImage removeColor(QImage &image, const QColor &color, int colorTolerance = 0, int alphaTolerance = 0);

    static QImage::Format getOutputFormat(MainSettingsModel::ForcedFormat forcedFormat, QImage::Format defaultFormat);

    static QColor getBackgroundColor(QImage::Format format);

    static bool hasAlpha(QImage::Format format);

    static bool isBackgroundColor(const QColor &color, const QColor &backgroundColor, int colorTolerance, int alphaTolerance);
};

#endif // IMAGEUTILS_H
