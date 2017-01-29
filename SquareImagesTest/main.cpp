#include <QTest>

#include "simplefilerecorddecryptortest.h"
#include "brandfilerecorddecryptortest.h"
#include "productfilerecorddecryptortest.h"

#include "squareimageconvertertest.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

    int status = 0;

    SimpleFileRecordDecryptorTest simpleFileRecordDecryptorTest;
    status |= QTest::qExec(&simpleFileRecordDecryptorTest);

    BrandFileRecordDecryptorTest brandFileRecordDecryptorTest;
    status |= QTest::qExec(&brandFileRecordDecryptorTest);

    ProductFileRecordDecryptorTest productFileRecordDecryptorTest;
    status |= QTest::qExec(&productFileRecordDecryptorTest);

    SquareImageConverterTest squareImageConverterTest;
    status |= QTest::qExec(&squareImageConverterTest);

    return status;
}
