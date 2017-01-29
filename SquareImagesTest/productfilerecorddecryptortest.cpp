#include "productfilerecorddecryptortest.h"

#include <QtTest>

#define protected public
#include "Core/productfilerecorddecryptor.h"
#undef protected

void ProductFileRecordDecryptorTest::decryptFileRecord_data() {

    QTest::addColumn<QString>("sourcePath");
    QTest::addColumn<QString>("outputPath");
    QTest::addColumn<QString>("fieldsString");
    QTest::addColumn<bool>("checkSubdirs");

    QTest::addColumn<QString>("inputFilePath");
    QTest::addColumn<QString>("inputFileName");
    QTest::addColumn<QString>("outputFilePath");
    QTest::addColumn<QString>("outputFileName");
    QTest::addColumn<QString>("error");

    QTest::newRow("Product: empty, none")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << ""
            << false
            << "" << ""
            << "" << ""
            << "";

    QTest::newRow("Product: empty, empty")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << ";"
            << false
            << "" << ""
            << "" << ""
            << "";

    QTest::newRow("Product: Fridge 1, none")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Fridge 1"
            << false
            << "" << ""
            << "" << ""
            << "Brand name is empty.";

    QTest::newRow("Product: Fridge 1, empty")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Fridge 1;;"
            << false
            << "" << ""
            << "" << ""
            << "Brand name is empty.";

    QTest::newRow("Product: Invalid, Panasonic")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Invalid;Panasonic"
            << false
            << "" << ""
            << "" << ""
            << "Nie znaleziono zdjęcia: Invalid, w folderze: E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor.";

    QTest::newRow("Product: Fridge 1, Panasonic")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Fridge 1;Panasonic"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "Fridge 1.png"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor/p/panasonic"
            << "fridge-1.png"
            << "";

    QTest::newRow("Product: Fridge 1, Krüger & Mätz")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Fridge 1;Krüger & Mätz"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "Fridge 1.png"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor/k/kruger-matz"
            << "fridge-1.png"
            << "";

    QTest::newRow("Product: Fridgę-1, Panasonic")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Fridgę-1;Panasonic"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "Fridge 1.png"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor/p/panasonic"
            << "fridge-1.png"
            << "";

    QTest::newRow("Product: Fridge 2, Krüger & Mätz")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Fridge 2;Krüger & Mätz"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "Fridge 2.jpg"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor/k/kruger-matz"
            << "fridge-2.jpg"
            << "";

    QTest::newRow("Product: Fridge 3, Krüger & Mätz")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Fridge 3;Krüger & Mätz"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "Fridgę 3.png"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor/k/kruger-matz"
            << "fridge-3.png"
            << "";

    QTest::newRow("Product: Fridge 4, Panasonic")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Fridge 4;Panasonic"
            << false
            << ""
            << ""
            << ""
            << ""
            << "Nie znaleziono zdjęcia: Fridge 4, w folderze: E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor.";

    QTest::newRow("Product: Fridge 4, Panasonic")
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor"
            << "Fridge 4;Panasonic"
            << true
            << "E:/QtApps/SquareImages/TestData/Input/ProductFileRecordDecryptor/Subfolder"
            << "Fridge 4.png"
            << "E:/QtApps/SquareImages/TestData/Output/ProductFileRecordDecryptor/p/panasonic"
            << "fridge-4.png"
            << "";
}

void ProductFileRecordDecryptorTest::decryptFileRecord() {
    QFETCH(QString, sourcePath);
    QFETCH(QString, outputPath);
    QFETCH(QString, fieldsString);
    QFETCH(bool, checkSubdirs);

    QFETCH(QString, inputFilePath);
    QFETCH(QString, inputFileName);
    QFETCH(QString, outputFilePath);
    QFETCH(QString, outputFileName);
    QFETCH(QString, error);

    MainSettingsModel model;
    model.setSourcePath(sourcePath);
    model.setOutputPath(outputPath);
    model.setCheckSubdirs(checkSubdirs);

    ProductFileRecordDecryptor decryptor(model);

    FileRecord result = decryptor.decryptFileRecord(fieldsString);

    QCOMPARE(result.inputFilePath, inputFilePath);
    QCOMPARE(result.inputFileName, inputFileName);
    QCOMPARE(result.outputFilePath, outputFilePath);
    QCOMPARE(result.outputFileName, outputFileName);
    QCOMPARE(result.getError(), error);
}
