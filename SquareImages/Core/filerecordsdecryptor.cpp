#include "filerecordsdecryptor.h"

#include <QFile>

#include <QDebug>

FileRecordsDecryptor::FileRecordsDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent) :
    FileRecordsCreator(imageRecordsModel, fileSettingsModel, parent),
    _fileRecordDecryptor(Q_NULLPTR)
{

}

FileRecordsDecryptor::~FileRecordsDecryptor() {
    _fileRecordDecryptor->deleteLater();
}


FileRecordDecryptor *FileRecordsDecryptor::getFileRecordDecryptor() const {
    return _fileRecordDecryptor;
}

void FileRecordsDecryptor::setFileRecordDecryptor(FileRecordDecryptor *fileRecordDecryptor) {
    if(_fileRecordDecryptor) {
        _fileRecordDecryptor->deleteLater();
    }

    _fileRecordDecryptor = fileRecordDecryptor;
}



void FileRecordsDecryptor::run() {
    processStarted();

    QFile file(_fileSettingsModel.getListFile());
    if(!file.open(QIODevice::ReadOnly)) {
        errorReported(tr("Nie można otworzyć pliku: ").arg(file.fileName()));
        processCanceled();
        return;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();

        FileRecord fileRecord = _fileRecordDecryptor->decryptFileRecord(line);

        if(!fileRecord.inputFileName.isEmpty() || !fileRecord.getError().isEmpty()) {
            _imageRecordsModel.addRecord(fileRecord);
        }

        if(isInterruptionRequested()) {
            file.close();
            processCanceled();
            return;
        }
    }

    file.close();
    processFinished();
}
