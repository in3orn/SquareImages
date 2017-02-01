#ifndef MIDTEXTIMAGECONVERTERTEST_H
#define MIDTEXTIMAGECONVERTERTEST_H


#include <QObject>

class MidTextImageConverterTest : public QObject
{
    Q_OBJECT

private slots:
    void convert_data();
    void convert();
};

#endif // MIDTEXTIMAGECONVERTERTEST_H
