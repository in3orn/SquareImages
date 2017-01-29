#ifndef SQUAREIMAGECONVERTERTEST_H
#define SQUAREIMAGECONVERTERTEST_H

#include <QObject>

class SquareImageConverterTest : public QObject
{
    Q_OBJECT

private slots:
    void getTopMargin_data();
    void getTopMargin();

    void getLeftMargin_data();
    void getLeftMargin();

    void getRightMargin_data();
    void getRightMargin();

    void getBottomMargin_data();
    void getBottomMargin();

    void getNewSize_data();
    void getNewSize();
};

#endif // SQUAREIMAGECONVERTERTEST_H
