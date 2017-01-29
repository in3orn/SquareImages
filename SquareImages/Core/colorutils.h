#ifndef COLORUTILS_H
#define COLORUTILS_H

#include <QImage>

class ColorUtils
{
public:
    static bool hasAlpha(QImage::Format format);
};

#endif // COLORUTILS_H
