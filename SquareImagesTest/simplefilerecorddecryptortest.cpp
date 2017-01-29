#include "simplefilerecorddecryptortest.h"

#include <QtTest>

#define protected public
#include "Core/simplefilerecorddecryptor.h"
#undef protected

void SimpleFileRecordDecryptorTest::decryptFileRecord_data() {

    QTest::addColumn<QString>("sourcePath");
    QTest::addColumn<QString>("outputPath");
    QTest::addColumn<QString>("fieldsString");
    QTest::addColumn<bool>("checkSubdirs");

    QTest::addColumn<QString>("inputFilePath");
    QTest::addColumn<QString>("inputFileName");
    QTest::addColumn<QString>("outputFilePath");
    QTest::addColumn<QString>("outputFileName");
    QTest::addColumn<QString>("error");

    QTest::newRow("Name, extension: empty, none")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << ""
            << false
            << ""
            << ""
            << ""
            << ""
            << "";

    QTest::newRow("Name, extension: empty, empty")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << ";;"
            << false
            << ""
            << ""
            << ""
            << ""
            << "";

    QTest::newRow("Name, extension: empty, some;path;extension")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << ";some;path;extension"
            << false
            << ""
            << ""
            << ""
            << ""
            << "";

    QTest::newRow("Name, extension: Invalid, none")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "Invalid"
            << false
            << ""
            << ""
            << ""
            << ""
            << "Nie znaleziono zdjęcia: Invalid, w folderze: E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor.";

    QTest::newRow("Name, extension: Invalid, empty")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "Invalid;"
            << false
            << ""
            << ""
            << ""
            << ""
            << "Nie znaleziono zdjęcia: Invalid, w folderze: E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor.";

    QTest::newRow("Name, extension: Invalid, some;path;extension")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "Invalid;some;path;extension"
            << false
            << ""
            << ""
            << ""
            << ""
            << "Nie znaleziono zdjęcia: Invalid, w folderze: E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor.";

    QTest::newRow("Name, extension: 3M, none")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "3M"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "3M.png"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "3m.png"
            << "";

    QTest::newRow("Name, extension: 3M, empty")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "3M;"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "3M.png"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "3m.png"
            << "";

    QTest::newRow("Name, extension: 3M, some;file;extension")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "3M;some;file;extension"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "3M.png"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor/some/file/extension"
            << "3m.png"
            << "";

    QTest::newRow("Name, extension: 3M, some; file ; extension")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "3M; some; file ; extension"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "3M.png"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor/some/file/extension"
            << "3m.png"
            << "";

    QTest::newRow("Name, extension: 3M, some;file/extension")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "3M;some;file/extension"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "3M.png"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor/some/file/extension"
            << "3m.png"
            << "";

    QTest::newRow("Name, extension: 3M, some;;file;;extension")
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor"
            << "3M;some;;file;;extension"
            << false
            << "E:/QtApps/SquareImages/TestData/Input/SimpleFileRecordDecryptor"
            << "3M.png"
            << "E:/QtApps/SquareImages/TestData/Output/SimpleFileRecordDecryptor/some/file/extension"
            << "3m.png"
            << "";
}

void SimpleFileRecordDecryptorTest::decryptFileRecord() {
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

    SimpleFileRecordDecryptor decryptor(model);

    FileRecord result = decryptor.decryptFileRecord(fieldsString);

    QCOMPARE(result.inputFilePath, inputFilePath);
    QCOMPARE(result.inputFileName, inputFileName);
    QCOMPARE(result.outputFilePath, outputFilePath);
    QCOMPARE(result.outputFileName, outputFileName);
    QCOMPARE(result.getError(), error);
}
