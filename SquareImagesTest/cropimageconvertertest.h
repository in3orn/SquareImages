#ifndef CROPIMAGECONVERTERTEST_H
#define CROPIMAGECONVERTERTEST_H

#include <QObject>

class CropImageConverterTest : public QObject
{
    Q_OBJECT

private slots:
    void getNewSize_data();
    void getNewSize();
};

#endif // CROPIMAGECONVERTERTEST_H
