#include "filerecorddecryptor.h"

#include "stringutils.h"

FileRecordDecryptor::FileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent) :
    FileRecordsCreator(imageRecordsModel, fileSettingsModel, parent),
    _fileRecordSettingsModel(fileSettingsModel)
{

}




FileRecord FileRecordDecryptor::decryptFileRecord(const QString &string) const {

    QStringList fields = string.split(";");

    FileRecord fileRecord = prepareFileRecord(fields);

    if(!fileRecord.inputFileName.isEmpty()) {
        fileRecord = getVerifiedFileRecord(fileRecord);
    }

    if(!fileRecord.inputFileName.isEmpty()) {
        fileRecord = extendFileRecord(fileRecord, fields);
    }

    return fileRecord;
}




FileRecord FileRecordDecryptor::prepareFileRecord(const QStringList &fields) const {
    FileRecord fileRecord;

    if(fields.size() < 1)
        return fileRecord;

    QString fileName = fields[0];

    if(fileName.isEmpty())
        return fileRecord;

    fileRecord.name = fileName;
    fileRecord.inputFilePath = _fileRecordSettingsModel.getSourcePath();
    fileRecord.inputFileName = fileName;

    return fileRecord;
}

FileRecord FileRecordDecryptor::getVerifiedFileRecord(const FileRecord &fileRecord) const {

    QDir directory(fileRecord.inputFilePath);
    QString fileName = StringUtils::normalizeName(fileRecord.inputFileName);
    fileName = StringUtils::removeFileExtension(fileName);

    FileRecord result = getFileRecord(directory, fileName);
    result.name = fileRecord.name;
    result = replaceFormat(result);

    if(result.inputFileName.isEmpty()) {
        result.setError(tr("Nie znaleziono zdjęcia: <b>%0</b>, w folderze: <br><b>%1</b>.").
                        arg(StringUtils::removeFileExtension(fileRecord.inputFileName), fileRecord.inputFilePath));
    }

    return result;
}

FileRecord FileRecordDecryptor::extendFileRecord(const FileRecord &fileRecord, const QStringList &fields) const {

    FileRecord result = fileRecord;

    if(!result.inputFileName.isEmpty()) {

        QString outputFilePathExtension = getOutputFileRecordExtension(fields);

        result.outputFilePath = _fileRecordSettingsModel.getOutputPath();
        result.outputFilePath += outputFilePathExtension;

    } else if(result.getError().isEmpty()) {
        result.setError(tr("Wystąpił <b>nieokreślony błąd</b> przy szukaniu obrazka."));
    }

    return result;
}




FileRecord FileRecordDecryptor::getFileRecord(const QDir &directory, const QString &searchedFileName) const {

    QFileInfoList fileInfos = directory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    QString bearSearchedFileName = searchedFileName;
    bearSearchedFileName.remove("-");

    for(int i = 0; i < fileInfos.size(); i++) {
        QFileInfo fileInfo = fileInfos[i];

        if(fileInfo.isDir() && _fileRecordSettingsModel.isCheckSubdirs()) {
            FileRecord result = getFileRecord(fileInfo.absoluteFilePath(), searchedFileName);
            if(!result.inputFileName.isEmpty()) {
                return result;
            }
        } else {
            QString normalizedName = StringUtils::normalizeName(fileInfo.fileName());
            QString checkName = StringUtils::removeFileExtension(normalizedName);

            if(searchedFileName == checkName || bearSearchedFileName == checkName) {
                return initFileRecord(fileInfo, searchedFileName + "." + StringUtils::getFileExtension(normalizedName));
            }
        }
    }

    return FileRecord();
}

FileRecord FileRecordDecryptor::initFileRecord(const QFileInfo &fileInfo, const QString &outputFileName) const {
    FileRecord result;

    result.inputFilePath = StringUtils::removeFileName(fileInfo.filePath());
    result.inputFileName = fileInfo.fileName();
    result.outputFileName = outputFileName;

    return result;
}

QString FileRecordDecryptor::getOutputFileRecordExtension(const QStringList &) const {
    return "";
}
