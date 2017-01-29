#include "colorutils.h"

bool ColorUtils::hasAlpha(QImage::Format format) {
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
