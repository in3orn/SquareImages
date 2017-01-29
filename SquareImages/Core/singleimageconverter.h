#ifndef SINGLEIMAGECONVERTER_H
#define SINGLEIMAGECONVERTER_H

#include "imagelistconverter.h"

class SingleImageConverter : public ImageListConverter
{
    Q_OBJECT

public:
    explicit SingleImageConverter(ImageConverter *imageConverter, QObject *parent = 0);

protected:
    virtual QList<FilePaths> getFilePathsList();
};

#endif // SINGLEIMAGECONVERTER_H
