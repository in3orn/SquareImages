#include "cropimageconvertertest.h"

#include <QtTest>

#define protected public
#include "Core/cropimageconverter.h"
#undef protected

void CropImageConverterTest::getNewSize_data()
{
    QTest::addColumn<int>("xRatio");
    QTest::addColumn<int>("yRatio");
    QTest::addColumn<QSize>("size");
    QTest::addColumn<QSize>("expected");

    QTest::newRow("Ratio 1:1 / 100x100") << 1 << 1 << QSize(100, 100) << QSize(100, 100);
    QTest::newRow("Ratio 1:1 / 50x100") << 1 << 1 << QSize(50, 100) << QSize(50, 50);
    QTest::newRow("Ratio 1:1 / 100x50") << 1 << 1 << QSize(100, 50) << QSize(50, 50);

    QTest::newRow("Ratio 2:1 / 100x100") << 2 << 1 << QSize(100, 100) << QSize(100, 50);
    QTest::newRow("Ratio 2:1 / 50x100") << 2 << 1 << QSize(50, 100) << QSize(50, 25);
    QTest::newRow("Ratio 2:1 / 100x50") << 2 << 1 << QSize(100, 50) << QSize(100, 50);

    QTest::newRow("Ratio 1:2 / 100x100") << 1 << 2 << QSize(100, 100) << QSize(50, 100);
    QTest::newRow("Ratio 1:2 / 50x100") << 1 << 2 << QSize(50, 100) << QSize(50, 100);
    QTest::newRow("Ratio 1:2 / 100x50") << 1 << 2 << QSize(100, 50) << QSize(25, 50);

    QTest::newRow("Ratio 16:9 / 100x100") << 16 << 9 << QSize(100, 100) << QSize(100, 56);
    QTest::newRow("Ratio 16:9 / 50x100") << 16 << 9 << QSize(50, 100) << QSize(50, 28);
    QTest::newRow("Ratio 16:9 / 100x50") << 16 << 9 << QSize(100, 50) << QSize(88, 50);

    QTest::newRow("Ratio 9:16 / 100x100") << 9 << 16 << QSize(100, 100) << QSize(56, 100);
    QTest::newRow("Ratio 9:16 / 50x100") << 9 << 16 << QSize(50, 100) << QSize(50, 88);
    QTest::newRow("Ratio 9:16 / 100x50") << 9 << 16 << QSize(100, 50) << QSize(28, 50);
}

void CropImageConverterTest::getNewSize()
{
    QFETCH(int, xRatio);
    QFETCH(int, yRatio);
    QFETCH(QSize, size);
    QFETCH(QSize, expected);

    MainSettingsModel fileSettingsModel;
    ConversionSettingsModel conversionSettingsModel;
    conversionSettingsModel.setXRatio(xRatio);
    conversionSettingsModel.setYRatio(yRatio);

    CropImageConverter converter(conversionSettingsModel, fileSettingsModel);

    QSize result = converter.getNewSize(size);

    QCOMPARE(result, expected);
}
