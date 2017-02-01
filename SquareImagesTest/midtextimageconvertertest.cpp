#include "midtextimageconvertertest.h"

#include <QtTest>

#define protected public
#include "Core/midtextimageconverter.h"
#undef protected

void MidTextImageConverterTest::convert_data()
{
    QTest::addColumn<QString>("sourcePath");
    QTest::addColumn<QString>("outputPath");
    QTest::addColumn<QColor>("color");
    QTest::addColumn<QSize>("size");
    QTest::addColumn<MainSettingsModel::ForcedFormat>("forcedFormat");



    QTest::newRow("PNG Image 100x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-100x200.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-100x200.png"
            << QColor("transparent")
            << QSize(100, 200)
            << MainSettingsModel::ForceNone;

    QTest::newRow("PNG Image 300x300")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-300x300.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-300x300.png"
            << QColor("transparent")
            << QSize(300, 300)
            << MainSettingsModel::ForceNone;

    QTest::newRow("PNG Image 400x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-400x200.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-400x200.png"
            << QColor("transparent")
            << QSize(400, 200)
            << MainSettingsModel::ForceNone;



    QTest::newRow("JPG Image 100x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-100x200.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-100x200.jpg"
            << QColor("white")
            << QSize(100, 200)
            << MainSettingsModel::ForceNone;

    QTest::newRow("JPG Image 300x300")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-300x300.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-300x300.jpg"
            << QColor("white")
            << QSize(300, 300)
            << MainSettingsModel::ForceNone;

    QTest::newRow("JPG Image 400x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-400x200.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-400x200.jpg"
            << QColor("white")
            << QSize(400, 200)
            << MainSettingsModel::ForceNone;



    QTest::newRow("Forced PNG Image 100x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-100x200.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-100x200-forced.png"
            << QColor("transparent")
            << QSize(100, 200)
            << MainSettingsModel::ForcePng;

    QTest::newRow("Forced PNG Image 300x300")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-300x300.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-300x300-forced.png"
            << QColor("transparent")
            << QSize(300, 300)
            << MainSettingsModel::ForcePng;

    QTest::newRow("Forced PNG Image 400x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-400x200.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-400x200-forced.png"
            << QColor("transparent")
            << QSize(400, 200)
            << MainSettingsModel::ForcePng;



    QTest::newRow("Forced JPG Image 100x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-100x200.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-100x200-forced.jpg"
            << QColor("white")
            << QSize(100, 200)
            << MainSettingsModel::ForceJpg;

    QTest::newRow("Forced JPG Image 300x300")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-300x300.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-300x300-forced.jpg"
            << QColor("white")
            << QSize(300, 300)
            << MainSettingsModel::ForceJpg;

    QTest::newRow("Forced JPG Image 400x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-400x200.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextMid\\rect-400x200-forced.jpg"
            << QColor("white")
            << QSize(400, 200)
            << MainSettingsModel::ForceJpg;
}

void MidTextImageConverterTest::convert() {
    QFETCH(QString, sourcePath);
    QFETCH(QString, outputPath);
    QFETCH(QColor, color);
    QFETCH(QSize, size);
    QFETCH(MainSettingsModel::ForcedFormat, forcedFormat);


    MainSettingsModel fileSettingsModel;
    fileSettingsModel.setForcedFormat(forcedFormat);

    ConversionSettingsModel conversionSettingsModel;
    conversionSettingsModel.setBackgroundColor("cornflowerblue");

    MidTextImageConverter converter(conversionSettingsModel, fileSettingsModel);

    QImage image;
    image.load(sourcePath);

    QImage newImage = converter.convert(image);
    newImage.save(outputPath);

    QSize newSize = newImage.size();
    QColor newColor = newImage.pixelColor(QPoint());

    QCOMPARE(newSize, size);
    QCOMPARE(newColor, color);
}
