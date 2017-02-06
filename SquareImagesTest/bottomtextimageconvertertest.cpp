#include "bottomtextimageconvertertest.h"

#include <QtTest>

#define protected public
#include "Core/bottomtextimageconverter.h"
#undef protected

void BottomTextImageConverterTest::convert_data()
{
    QTest::addColumn<QString>("sourcePath");
    QTest::addColumn<QString>("outputPath");
    QTest::addColumn<QColor>("color");
    QTest::addColumn<QSize>("size");
    QTest::addColumn<MainSettingsModel::ForcedFormat>("forcedFormat");



    QTest::newRow("PNG Image 100x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-100x200.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-100x200.png"
            << QColor("transparent")
            << QSize(100, 220)
            << MainSettingsModel::ForceNone;

    QTest::newRow("PNG Image 300x300")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-300x300.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-300x300.png"
            << QColor("transparent")
            << QSize(300, 360)
            << MainSettingsModel::ForceNone;

    QTest::newRow("PNG Image 400x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-400x200.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-400x200.png"
            << QColor("transparent")
            << QSize(400, 280)
            << MainSettingsModel::ForceNone;



    QTest::newRow("JPG Image 100x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-100x200.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-100x200.jpg"
            << QColor("white")
            << QSize(100, 220)
            << MainSettingsModel::ForceNone;

    QTest::newRow("JPG Image 300x300")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-300x300.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-300x300.jpg"
            << QColor("white")
            << QSize(300, 360)
            << MainSettingsModel::ForceNone;

    QTest::newRow("JPG Image 400x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-400x200.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-400x200.jpg"
            << QColor("white")
            << QSize(400, 280)
            << MainSettingsModel::ForceNone;



    QTest::newRow("Forced PNG Image 100x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-100x200.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-100x200-forced.png"
            << QColor("transparent")
            << QSize(100, 220)
            << MainSettingsModel::ForcePng;

    QTest::newRow("Forced PNG Image 300x300")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-300x300.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-300x300-forced.png"
            << QColor("transparent")
            << QSize(300, 360)
            << MainSettingsModel::ForcePng;

    QTest::newRow("Forced PNG Image 400x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-400x200.jpg"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-400x200-forced.png"
            << QColor("transparent")
            << QSize(400, 280)
            << MainSettingsModel::ForcePng;



    QTest::newRow("Forced JPG Image 100x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-100x200.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-100x200-forced.jpg"
            << QColor("white")
            << QSize(100, 220)
            << MainSettingsModel::ForceJpg;

    QTest::newRow("Forced JPG Image 300x300")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-300x300.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-300x300-forced.jpg"
            << QColor("white")
            << QSize(300, 360)
            << MainSettingsModel::ForceJpg;

    QTest::newRow("Forced JPG Image 400x200")
            << "E:\\QtApps\\SquareImages\\TestData\\Input\\Text\\rect-400x200.png"
            << "E:\\QtApps\\SquareImages\\TestData\\Output\\TextBottom\\rect-400x200-forced.jpg"
            << QColor("white")
            << QSize(400, 280)
            << MainSettingsModel::ForceJpg;
}

void BottomTextImageConverterTest::convert() {
    QFETCH(QString, sourcePath);
    QFETCH(QString, outputPath);
    QFETCH(QColor, color);
    QFETCH(QSize, size);
    QFETCH(MainSettingsModel::ForcedFormat, forcedFormat);


    MainSettingsModel fileSettingsModel;
    fileSettingsModel.setForcedFormat(forcedFormat);

    ConversionSettingsModel conversionSettingsModel;
    conversionSettingsModel.setBackgroundColor("darkblue");

    BottomTextImageConverter converter(conversionSettingsModel, fileSettingsModel);

    QImage image;
    image.load(sourcePath);

    QImage newImage = converter.convert(image, FileRecord());
    newImage.save(outputPath);

    QSize newSize = newImage.size();
    QColor newColor = newImage.pixelColor(QPoint(0, newImage.height()-1));

    QCOMPARE(newSize, size);
    QCOMPARE(newColor, color);
}
