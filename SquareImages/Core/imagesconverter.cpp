#include "imagesconverter.h"

#include <QDir>
#include <QImageReader>
#include <QImageWriter>

ImagesConverter::ImagesConverter(ImageRecordsModel &imageRecordsModel, MainSettingsModel &mainSettingsModel, QObject *parent) : QThread(parent),
    _imageRecordsModel(imageRecordsModel),
    _mainSettingsModel(mainSettingsModel),
    _imageConverter(Q_NULLPTR)
{

}

ImagesConverter::~ImagesConverter() {
    delete _imageConverter;
}



ImageConverter *ImagesConverter::getImageConverter() const {
    return _imageConverter;
}

void ImagesConverter::setImageConverter(ImageConverter *imageConverter) {
    if(_imageConverter) {
        delete _imageConverter;
    }

    _imageConverter = imageConverter;
}



void ImagesConverter::run() {
    processStarted();

    for(int i = 0; i < _imageRecordsModel.rowCount(); i++) {
        FileRecord fileRecord = _imageRecordsModel.getRecord(i);

        if(fileRecord.getError().isEmpty()) {
            bool convert = true;
            if(!_mainSettingsModel.isReplaceExisting()) {
                QDir existing(fileRecord.outputFilePath);
                if(existing.exists(fileRecord.outputFileName)) {
                    convert = false;
                }
            }

            if(convert) {
                QString inputFile = fileRecord.inputFilePath + "/" + fileRecord.inputFileName;
                QString outputFile = fileRecord.outputFilePath + "/" + fileRecord.outputFileName;

                QImageReader reader(inputFile);

                QImage inputImage;
                if(reader.read(&inputImage)) {
                    QImage outputImage = _imageConverter->convert(inputImage, fileRecord);

                    preparePath(fileRecord.outputFilePath);

                    QImageWriter writer(outputFile);

                    if(writer.supportsOption(QImageIOHandler::Quality)) {
                        writer.setQuality(_mainSettingsModel.getImageQuality());
                    }

                    if(!writer.write(outputImage)) {
                        fileRecord.setError(tr("Nie można zapisać pliku: <b>%0</b>.").arg(outputFile));
                    }
                } else {
                    fileRecord.setError(tr("Nie można wczytać pliku: <b>%0</b>.<br><i>%1</i>").arg(inputFile, reader.errorString()));
                }

                fileRecord.finish();
            } else {
                fileRecord.omit();
            }

            _imageRecordsModel.setRecord(i, fileRecord);
        }

        progressChanged((double)(i+1)/(double)_imageRecordsModel.rowCount());

        if (isInterruptionRequested()) {
            processCanceled();
            return;
        }
    }

    processFinished();
}

void ImagesConverter::preparePath(const QString &path) {
    QStringList folders = path.split("/");
    QDir dir(folders.first());
    for(int i = 1; i < folders.size(); ++i) {
        QString folder = folders[i];
        dir.mkdir(folder);
        dir.cd(folder);
    }
}
