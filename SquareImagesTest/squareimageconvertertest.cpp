#include "squareimageconvertertest.h"

#include <QtTest>

#include <QImage>

#define protected public
#include "Core/squareimageconverter.h"
#undef protected

void SquareImageConverterTest::getTopMargin_data()
{
    QTest::addColumn<QString>("imagePath");
    QTest::addColumn<int>("margin");

    QTest::newRow("Brand-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-1.png" << 69;
    QTest::newRow("Brand-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-2.png" << 99;
    QTest::newRow("Brand-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-3.png" << 306;
    QTest::newRow("Brand-4") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-4.png" << 3;
    QTest::newRow("Brand-5") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-5.png" << 30;

    QTest::newRow("Fridge-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-1.png" << 0;
    QTest::newRow("Fridge-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-2.png" << 0;
    QTest::newRow("Fridge-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-3.png" << 77;

    QTest::newRow("TV-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-1.png" << 196;
    QTest::newRow("TV-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-2.png" << 187;
    QTest::newRow("TV-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-3.png" << 22;
}

void SquareImageConverterTest::getTopMargin()
{
    QFETCH(QString, imagePath);
    QFETCH(int, margin);

    MainSettingsModel fileSettingsModel;
    ConversionSettingsModel conversionSettingsModel;

    QImage image;
    image.load(imagePath);
    SquareImageConverter converter(conversionSettingsModel, fileSettingsModel);

    int result = converter.getTopMargin(image);

    QCOMPARE(result, margin);
}

void SquareImageConverterTest::getLeftMargin_data()
{
    QTest::addColumn<QString>("imagePath");
    QTest::addColumn<int>("margin");

    QTest::newRow("Brand-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-1.png" << 140;
    QTest::newRow("Brand-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-2.png" << 101;
    QTest::newRow("Brand-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-3.png" << 95;
    QTest::newRow("Brand-4") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-4.png" << 7;
    QTest::newRow("Brand-5") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-5.png" << 38;

    QTest::newRow("Fridge-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-1.png" << 0;
    QTest::newRow("Fridge-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-2.png" << 0;
    QTest::newRow("Fridge-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-3.png" << 78;

    QTest::newRow("TV-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-1.png" << 190;
    QTest::newRow("TV-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-2.png" << 200;
    QTest::newRow("TV-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-3.png" << 45;
}

void SquareImageConverterTest::getLeftMargin()
{
    QFETCH(QString, imagePath);
    QFETCH(int, margin);

    MainSettingsModel fileSettingsModel;
    ConversionSettingsModel conversionSettingsModel;

    QImage image;
    image.load(imagePath);
    SquareImageConverter converter(conversionSettingsModel, fileSettingsModel);

    int result = converter.getLeftMargin(image);

    QCOMPARE(result, margin);
}

void SquareImageConverterTest::getRightMargin_data()
{
    QTest::addColumn<QString>("imagePath");
    QTest::addColumn<int>("margin");

    QTest::newRow("Brand-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-1.png" << 139;
    QTest::newRow("Brand-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-2.png" << 99;
    QTest::newRow("Brand-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-3.png" << 114;
    QTest::newRow("Brand-4") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-4.png" << 7;
    QTest::newRow("Brand-5") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-5.png" << 42;

    QTest::newRow("Fridge-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-1.png" << 0;
    QTest::newRow("Fridge-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-2.png" << 0;
    QTest::newRow("Fridge-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-3.png" << 76;

    QTest::newRow("TV-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-1.png" << 190;
    QTest::newRow("TV-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-2.png" << 202;
    QTest::newRow("TV-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-3.png" << 50;
}

void SquareImageConverterTest::getRightMargin()
{
    QFETCH(QString, imagePath);
    QFETCH(int, margin);

    MainSettingsModel fileSettingsModel;
    ConversionSettingsModel conversionSettingsModel;

    QImage image;
    image.load(imagePath);
    SquareImageConverter converter(conversionSettingsModel, fileSettingsModel);

    int result = converter.getRightMargin(image);

    QCOMPARE(result, margin);
}

void SquareImageConverterTest::getBottomMargin_data()
{
    QTest::addColumn<QString>("imagePath");
    QTest::addColumn<int>("margin");

    QTest::newRow("Brand-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-1.png" << 94;
    QTest::newRow("Brand-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-2.png" << 95;
    QTest::newRow("Brand-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-3.png" << 304;
    QTest::newRow("Brand-4") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-4.png" << 5;
    QTest::newRow("Brand-5") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\brand-5.png" << 30;

    QTest::newRow("Fridge-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-1.png" << 41;
    QTest::newRow("Fridge-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-2.png" << 0;
    QTest::newRow("Fridge-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\fridge-3.png" << 51;

    QTest::newRow("TV-1") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-1.png" << 187;
    QTest::newRow("TV-2") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-2.png" << 98;
    QTest::newRow("TV-3") << "E:\\QtApps\\SquareImages\\TestData\\Input\\SquareImageConverter\\tv-3.png" << 190;
}

void SquareImageConverterTest::getBottomMargin()
{
    QFETCH(QString, imagePath);
    QFETCH(int, margin);

    MainSettingsModel fileSettingsModel;
    ConversionSettingsModel conversionSettingsModel;

    QImage image;
    image.load(imagePath);
    SquareImageConverter converter(conversionSettingsModel, fileSettingsModel);

    int result = converter.getBottomMargin(image);

    QCOMPARE(result, margin);
}

void SquareImageConverterTest::getNewSize_data()
{
    QTest::addColumn<int>("xRatio");
    QTest::addColumn<int>("yRatio");
    QTest::addColumn<QSize>("size");
    QTest::addColumn<QSize>("expected");

    QTest::newRow("Ratio 1:1 / 100x100") << 1 << 1 << QSize(100, 100) << QSize(100, 100);
    QTest::newRow("Ratio 1:1 / 50x100") << 1 << 1 << QSize(50, 100) << QSize(100, 100);
    QTest::newRow("Ratio 1:1 / 100x50") << 1 << 1 << QSize(100, 50) << QSize(100, 100);

    QTest::newRow("Ratio 2:1 / 100x100") << 2 << 1 << QSize(100, 100) << QSize(200, 100);
    QTest::newRow("Ratio 2:1 / 50x100") << 2 << 1 << QSize(50, 100) << QSize(200, 100);
    QTest::newRow("Ratio 2:1 / 100x50") << 2 << 1 << QSize(100, 50) << QSize(100, 50);

    QTest::newRow("Ratio 1:2 / 100x100") << 1 << 2 << QSize(100, 100) << QSize(100, 200);
    QTest::newRow("Ratio 1:2 / 50x100") << 1 << 2 << QSize(50, 100) << QSize(50, 100);
    QTest::newRow("Ratio 1:2 / 100x50") << 1 << 2 << QSize(100, 50) << QSize(100, 200);

    QTest::newRow("Ratio 16:9 / 100x100") << 16 << 9 << QSize(100, 100) << QSize(177, 100);
    QTest::newRow("Ratio 16:9 / 50x100") << 16 << 9 << QSize(50, 100) << QSize(177, 100);
    QTest::newRow("Ratio 16:9 / 100x50") << 16 << 9 << QSize(100, 50) << QSize(100, 56);

    QTest::newRow("Ratio 9:16 / 100x100") << 9 << 16 << QSize(100, 100) << QSize(100, 177);
    QTest::newRow("Ratio 9:16 / 50x100") << 9 << 16 << QSize(50, 100) << QSize(56, 100);
    QTest::newRow("Ratio 9:16 / 100x50") << 9 << 16 << QSize(100, 50) << QSize(100, 177);
}

void SquareImageConverterTest::getNewSize()
{
    QFETCH(int, xRatio);
    QFETCH(int, yRatio);
    QFETCH(QSize, size);
    QFETCH(QSize, expected);

    MainSettingsModel fileSettingsModel;
    ConversionSettingsModel conversionSettingsModel;
    conversionSettingsModel.setXRatio(xRatio);
    conversionSettingsModel.setYRatio(yRatio);

    SquareImageConverter converter(conversionSettingsModel, fileSettingsModel);

    QSize result = converter.getNewSize(size);

    QCOMPARE(result, expected);
}
