#include "brandfilerecorddecryptortest.h"

#include <QtTest>

#define protected public
#include "Core/brandfilerecorddecryptor.h"
#undef protected

void BrandFileRecordDecryptorTest::decryptFileRecord_data() {

    QTest::addColumn<QString>("sourcePath");
    QTest::addColumn<QString>("outputPath");
    QTest::addColumn<QString>("fieldsString");
    QTest::addColumn<bool>("checkSubdirs");

    QTest::addColumn<QString>("inputFilePath");
    QTest::addColumn<QString>("inputFileName");
    QTest::addColumn<QString>("outputFilePath");
    QTest::addColumn<QString>("outputFileName");
    QTest::addColumn<QString>("error");

    QTest::newRow("Brand: empty")
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor"
            << ""
            << false
            << ""
            << ""
            << ""
            << ""
            << "";

    QTest::newRow("Brand: Invalid")
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor"
            << "Invalid"
            << false
            << ""
            << ""
            << ""
            << ""
            << "Nie znaleziono zdjęcia: <b>Invalid</b>, w folderze: <br><b>E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor</b>.";

    QTest::newRow("Brand: 3M")
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor"
            << "3M"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "3M.png"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor/3"
            << "3m.png"
            << "";

    QTest::newRow("Brand: Ascaso")
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor"
            << "Ascaso"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "ascaso.jpg"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor/a"
            << "ascaso.jpg"
            << "";

    QTest::newRow("Brand: Apple")
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor"
            << "Apple"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "ápplę.png"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor/a"
            << "apple.png"
            << "";

    QTest::newRow("Brand: Solis")
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor"
            << "Solis"
            << false
            << ""
            << ""
            << ""
            << ""
            << "Nie znaleziono zdjęcia: <b>Solis</b>, w folderze: <br><b>E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor</b>.";

    QTest::newRow("Brand: Solis")
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor"
            << "Solis"
            << true
            << "E:/QtApps/SquareImages/TestData/Input/BrandFileRecordDecryptor/Subfolder"
            << "Solis.png"
            << "E:/QtApps/SquareImages/TestData/Output/BrandFileRecordDecryptor/s"
            << "solis.png"
            << "";
}

void BrandFileRecordDecryptorTest::decryptFileRecord() {
    QFETCH(QString, sourcePath);
    QFETCH(QString, outputPath);
    QFETCH(QString, fieldsString);
    QFETCH(bool, checkSubdirs);

    QFETCH(QString, inputFilePath);
    QFETCH(QString, inputFileName);
    QFETCH(QString, outputFilePath);
    QFETCH(QString, outputFileName);
    QFETCH(QString, error);


    ImageRecordsModel imageRecordsModel;
    MainSettingsModel fileSettingsModel;
    fileSettingsModel.setSourcePath(sourcePath);
    fileSettingsModel.setOutputPath(outputPath);
    fileSettingsModel.setCheckSubdirs(checkSubdirs);

    BrandFileRecordDecryptor decryptor(imageRecordsModel, fileSettingsModel);

    FileRecord result = decryptor.decryptFileRecord(fieldsString);

    QCOMPARE(result.inputFilePath, inputFilePath);
    QCOMPARE(result.inputFileName, inputFileName);
    QCOMPARE(result.outputFilePath, outputFilePath);
    QCOMPARE(result.outputFileName, outputFileName);
    QCOMPARE(result.getError(), error);
}
