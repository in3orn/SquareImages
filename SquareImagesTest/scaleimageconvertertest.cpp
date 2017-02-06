#include "scaleimageconvertertest.h"

#include <QtTest>

#define protected public
#include "Core/scaleimageconverter.h"
#undef protected

void ScaleImageConverterTest::convert_data()
{
    QTest::addColumn<QString>("imagePath");

    QTest::newRow("Scale image") << "E:\\QtApps\\SquareImages\\TestData\\Input\\Scale\\Solis.png";
}

void ScaleImageConverterTest::convert()
{
    QFETCH(QString, imagePath);

    MainSettingsModel fileSettingsModel;
    ConversionSettingsModel conversionSettingsModel;
    conversionSettingsModel.setMaxScaleStrategy(ConversionSettingsModel::MaxScaleWidth);
    conversionSettingsModel.setMaxScaleValue(600);

    ScaleImageConverter converter(conversionSettingsModel, fileSettingsModel);

    QImage image;
    image.load(imagePath);

    QBENCHMARK(converter.convert(image, FileRecord()));
}
