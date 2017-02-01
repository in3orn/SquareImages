#ifndef IMAGECONVERTER_H
#define IMAGECONVERTER_H

#include <QImage>

#include "Model/mainsettingsmodel.h"

#include "filerecord.h"

class ImageConverter
{
public:
    virtual ~ImageConverter() {}

    virtual QImage convert(const QImage &image, const FileRecord &fileRecord) = 0;
};

#endif // IMAGECONVERTER_H
