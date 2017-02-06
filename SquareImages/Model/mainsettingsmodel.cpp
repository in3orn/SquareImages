#include "mainsettingsmodel.h"

QStringList MainSettingsModel::initConvertsionTypeNames()
{
    QStringList names;

    names << tr("Obrazek (pojedynczy)");
    names << tr("Obrazki z katalogu");
    names << tr("Obrazki z listy (dowolne)");
    names << tr("Obrazki z listy (marki)");
    names << tr("Obrazki z listy (produkty)");
    names << tr("Obrazki z listy (teksty)");

    return names;
}

QStringList MainSettingsModel::convertsionTypeNames = MainSettingsModel::initConvertsionTypeNames();

QStringList MainSettingsModel::initForcedFormatNames()
{
    QStringList names;

    names << tr("Brak");
    names << tr(".png");
    names << tr(".jpg");

    return names;
}

QStringList MainSettingsModel::forcedFormatNames = MainSettingsModel::initForcedFormatNames();




MainSettingsModel::MainSettingsModel(QObject *parent) : QObject(parent),

    _conversionType(ConversionType::ConvertSingleImage),

    _outputPath(""),
    _sourceFile(""),
    _sourcePath(""),
    _listFile(""),

    _checkSubdirs(false),
    _replaceExisting(false),

    _forcedFormat(ForceNone),

    _imageQuality(80)
{

}



MainSettingsModel::ConversionType MainSettingsModel::getConversionType() const {
    return _conversionType;
}

QString MainSettingsModel::getOutputPath() const {
    return _outputPath;
}

QString MainSettingsModel::getSourceFile() const {
    return _sourceFile;
}

QString MainSettingsModel::getSourcePath() const {
    return _sourcePath;
}

QString MainSettingsModel::getListFile() const {
    return _listFile;
}

bool MainSettingsModel::isCheckSubdirs() const {
    return _checkSubdirs;
}

bool MainSettingsModel::isReplaceExisting() const {
    return _replaceExisting;
}

MainSettingsModel::ForcedFormat MainSettingsModel::getForcedFormat() const {
    return _forcedFormat;
}

QString MainSettingsModel::getForcedFormatExtension() const
{
    switch(_forcedFormat)
    {
    case MainSettingsModel::ForcePng:
        return "png";
    case MainSettingsModel::ForceJpg:
        return "jpg";
    default:
        return "";
    }
}

int MainSettingsModel::getImageQuality() const {
    return _imageQuality;
}



void MainSettingsModel::setConversionType(ConversionType conversionType) {
    if(_conversionType != conversionType) {
        _conversionType = conversionType;
        emit conversionTypeChanged(static_cast<int>(conversionType));
        emit conversionTypeChanged(conversionType);
    }
}

void MainSettingsModel::setConversionType(int conversionType) {
    setConversionType(static_cast<ConversionType>(conversionType));
}

void MainSettingsModel::setOutputPath(const QString &outputPath) {
    if(_outputPath != outputPath) {
        _outputPath = outputPath;
        emit outputPathChanged(_outputPath);
    }
}

void MainSettingsModel::setSourceFile(const QString &sourceFile) {
    if(_sourceFile != sourceFile) {
        _sourceFile = sourceFile;
        emit sourceFileChanged(_sourceFile);
    }
}

void MainSettingsModel::setSourcePath(const QString &sourcePath) {
    if(_sourcePath != sourcePath) {
        _sourcePath = sourcePath;
        emit sourcePathChanged(_sourcePath);
    }
}

void MainSettingsModel::setListFile(const QString &listFile) {
    if(_listFile != listFile) {
        _listFile = listFile;
        emit listFileChanged(_listFile);
    }
}

void MainSettingsModel::setCheckSubdirs(bool checkSubdirs) {
    if(_checkSubdirs != checkSubdirs) {
        _checkSubdirs = checkSubdirs;
        emit checkSubdirsChanged(_checkSubdirs);
    }
}

void MainSettingsModel::setReplaceExisting(bool replaceExisting) {
    if(_replaceExisting != replaceExisting) {
        _replaceExisting = replaceExisting;
        emit replaceExistingChanged(_replaceExisting);
    }
}

void MainSettingsModel::setForcedFormat(ForcedFormat forcedFormat) {
    if(_forcedFormat != forcedFormat) {
        _forcedFormat = forcedFormat;
        emit forcedFormatChanged(static_cast<int>(forcedFormat));
        emit forcedFormatChanged(forcedFormat);
    }
}

void MainSettingsModel::setForcedFormat(int forcedFormat) {
    setForcedFormat(static_cast<ForcedFormat>(forcedFormat));
}

void MainSettingsModel::setImageQuality(int imageQuality) {
    if(_imageQuality != imageQuality) {
        _imageQuality = imageQuality;
        emit imageQualityChanged(imageQuality);
    }
}
