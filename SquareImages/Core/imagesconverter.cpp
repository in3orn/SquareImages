#include "imagesconverter.h"

#include <QDir>

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

                QImage inputImage;
                if(inputImage.load(inputFile)) {
                    QImage outputImage = _imageConverter->convert(inputImage);

                    preparePath(fileRecord.outputFilePath);

                    if(!outputImage.save(outputFile)) {
                        fileRecord.setError(tr("Nie można zapisać pliku: %0.").arg(outputFile));
                    }
                } else {
                    fileRecord.setError(tr("Nie można wczytać pliku: %0.").arg(inputFile));
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
