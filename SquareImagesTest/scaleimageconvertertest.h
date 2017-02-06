#ifndef SCALEIMAGECONVERTERTEST_H
#define SCALEIMAGECONVERTERTEST_H

#include <QObject>

class ScaleImageConverterTest : public QObject
{
    Q_OBJECT

private slots:
    void convert_data();
    void convert();
};

#endif // SCALEIMAGECONVERTERTEST_H
