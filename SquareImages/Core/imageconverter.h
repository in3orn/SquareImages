#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include <QImage>

class ImageConverter
{
public:
    virtual ~ImageConverter() {}

public:
    virtual QImage convert(const QImage &image) const = 0;
};

#endif // IMAGECONVERTER_H
