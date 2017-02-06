#include "filerecordsdecryptor.h"

#include <QFile>
#include <QTextStream>

#include "stringutils.h"

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

    QString extendedName = file.fileName().replace(".csv", "-extended.csv");
    QFile extendedFile(extendedName);
    if(!extendedFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        errorReported(tr("Nie można utworzyć pliku rozszerzonego: ").arg(extendedName));
        processCanceled();
        return;
    }

    QTextStream in(&file);

    QTextStream out(&extendedFile);
    out.setCodec("UTF-8");

    while(!in.atEnd()) {
        QString line = in.readLine();

        int fields = line.split(";").size();

        FileRecord fileRecord = _fileRecordDecryptor->decryptFileRecord(line);

        out << line;
        for(int i = fields; i < 6; i++) out << ";";

        if(!fileRecord.inputFileName.isEmpty() || !fileRecord.getError().isEmpty()) {
            _imageRecordsModel.addRecord(fileRecord);
            if(fileRecord.getError().isEmpty()) {
                out << StringUtils::getFileExtension(fileRecord.outputFileName);
            }
        }

        out << "\n";

        if(isInterruptionRequested()) {
            file.close();
            extendedFile.close();
            processCanceled();
            return;
        }
    }

    file.close();
    extendedFile.close();
    processFinished();
}
