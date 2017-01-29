#include "conversionmodel.h"

ConversionModel::ConversionModel(QObject *parent) : QObject(parent),

    _running(false),
    _progress(0)
{

}



bool ConversionModel::isRunning() const {
    return _running;
}

int ConversionModel::getProgress() const {
    return _progress;
}



void ConversionModel::setRunning(bool running) {
    if(_running != running) {
        _running = running;
        runningChanged(_running);
    }
}

void ConversionModel::setProgress(int progress) {
    if(_progress != progress) {
        _progress = progress;
        progressChanged(_progress);
    }
}
