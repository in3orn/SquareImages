#include <QTest>

#include "simplefilerecorddecryptortest.h"
#include "brandfilerecorddecryptortest.h"
#include "productfilerecorddecryptortest.h"

#include "cropimageconvertertest.h"
#include "squareimageconvertertest.h"

#include "toptextimageconvertertest.h"
#include "midtextimageconvertertest.h"
#include "bottomtextimageconvertertest.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Q_UNUSED(app);

    int status = 0;

    SimpleFileRecordDecryptorTest simpleFileRecordDecryptorTest;
    status |= QTest::qExec(&simpleFileRecordDecryptorTest);

    BrandFileRecordDecryptorTest brandFileRecordDecryptorTest;
    status |= QTest::qExec(&brandFileRecordDecryptorTest);

    ProductFileRecordDecryptorTest productFileRecordDecryptorTest;
    status |= QTest::qExec(&productFileRecordDecryptorTest);

    CropImageConverterTest cropImageConverterTest;
    status |= QTest::qExec(&cropImageConverterTest);

    SquareImageConverterTest squareImageConverterTest;
    status |= QTest::qExec(&squareImageConverterTest);

    TopTextImageConverterTest topTextImageConverterTest;
    status |= QTest::qExec(&topTextImageConverterTest);

    MidTextImageConverterTest midTextImageConverterTest;
    status |= QTest::qExec(&midTextImageConverterTest);

    BottomTextImageConverterTest bottomTextImageConverterTest;
    status |= QTest::qExec(&bottomTextImageConverterTest);

    return status;
}
