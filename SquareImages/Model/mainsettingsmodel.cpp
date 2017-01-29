#include "mainsettingsmodel.h"

#include <QDebug>

MainSettingsModel::MainSettingsModel(QObject *parent) : QObject(parent),

    _conversionType(0),

    _outputPath(""),
    _sourceFile(""),
    _sourcePath(""),
    _listFile(""),

    _checkSubdirs(false),
    _replaceExisting(false),

    _forcedFormat(None)
{

}



int MainSettingsModel::getConversionType() const {
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

int MainSettingsModel::getForcedFormat() const {
    return _forcedFormat;
}



void MainSettingsModel::setConversionType(int conversionType) {
    if(_conversionType != conversionType) {
        _conversionType = conversionType;
        emit conversionTypeChanged(_conversionType);
    }
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

void MainSettingsModel::setForcedFormat(int forcedFormat) {
    ForcedFormat forcedFormatEnum = static_cast<ForcedFormat>(forcedFormat);
    if(_forcedFormat != forcedFormatEnum) {
        _forcedFormat = forcedFormatEnum;
        emit forcedFormatChanged(forcedFormat);
    }
}
