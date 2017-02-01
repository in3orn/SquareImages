#include "imageutils.h"

#include <QPainter>

QImage ImageUtils::insertImage(QImage &image, const QImage &inserted, const QPoint &topLeft)
{
    for(int x = 0; x < inserted.width(); x++) {
        for(int y = 0; y < inserted.height(); y++) {
            QColor color = inserted.pixelColor(x, y);
            image.setPixelColor(topLeft.x() + x, topLeft.y() + y, color);
        }
    }

    return image;
}

QImage ImageUtils::insertImageRegion(QImage &image, const QImage &inserted, const QRect &region, const QPoint &topLeft)
{
    for(int x = 0; x < region.width(); x++) {
        for(int y = 0; y < region.height(); y++) {
            QColor color = inserted.pixelColor(region.x() + x, region.y() + y);
            image.setPixelColor(topLeft.x() + x, topLeft.y() + y, color);
        }
    }

    return image;
}

QImage ImageUtils::insertCroppedImage(QImage &image, const QImage &inserted, const QPoint &topLeft)
{
    for(int x = 0; x < image.width(); x++) {
        for(int y = 0; y < image.height(); y++) {
            QColor color = inserted.pixelColor(topLeft.x() + x, topLeft.y() + y);
            image.setPixelColor(x, y, color);
        }
    }

    return image;
}

QImage ImageUtils::insertText(QImage &image, const PaintTextSettings &settings, const QString &text)
{
    QPainter painter(&image);
    painter.setPen(settings.pen);
    painter.setFont(settings.font);
    painter.drawText(settings.rect, settings.alignment, text);

    return image;
}

QImage ImageUtils::removeColor(QImage &image, const QColor &color, int colorTolerance, int alphaTolerance)
{
    QColor backgroundColor = getBackgroundColor(image.format());

    for(int x = 0; x < image.width(); x++) {
        for(int y = 0; y < image.height(); y++) {
            QColor imageColor = image.pixelColor(x, y);
            if(isBackgroundColor(imageColor, color, colorTolerance, alphaTolerance)) {
                image.setPixelColor(x, y, backgroundColor);
            }
        }
    }

    return image;
}

QImage::Format ImageUtils::getOutputFormat(MainSettingsModel::ForcedFormat forcedFormat, QImage::Format defaultFormat)
{
    switch(forcedFormat)
    {
    case MainSettingsModel::ForcePng:
        return QImage::Format_RGBA8888;
    case MainSettingsModel::ForceJpg:
        return QImage::Format_RGB888;
    default:
        return defaultFormat;
    }
}

QColor ImageUtils::getBackgroundColor(QImage::Format format)
{
    return QColor(hasAlpha(format) ? "transparent" : "white");
}

bool ImageUtils::hasAlpha(QImage::Format format)
{
    if(format == QImage::Format_RGB16) return false;
    if(format == QImage::Format_RGB30) return false;
    if(format == QImage::Format_RGB32) return false;

    if(format == QImage::Format_RGB444) return false;
    if(format == QImage::Format_RGB555) return false;
    if(format == QImage::Format_RGB666) return false;
    if(format == QImage::Format_RGB888) return false;

    if(format == QImage::Format_BGR30) return false;

    return true;
}

bool ImageUtils::isBackgroundColor(const QColor &color, const QColor &backgroundColor, int colorTolerance, int alphaTolerance)
{
    if(color.alpha() <= alphaTolerance) return true;

    if(qAbs(color.red() - backgroundColor.red()) > colorTolerance) return false;
    if(qAbs(color.green() - backgroundColor.green()) > colorTolerance) return false;
    if(qAbs(color.blue() - backgroundColor.blue()) > colorTolerance) return false;

    return true;
}
