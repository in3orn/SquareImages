#include "directoryfilerecordscreator.h"

#include "stringutils.h"

DirectoryFileRecordsCreator::DirectoryFileRecordsCreator(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent) :
    FileRecordsCreator(imageRecordsModel, fileSettingsModel, parent)
{

}

void DirectoryFileRecordsCreator::run() {
    processStarted();

    QDir directory(_fileSettingsModel.getSourcePath());

    processDirectory(directory);

    if(isInterruptionRequested()) {
        processCanceled();
        return;
    }

    processFinished();
}

void DirectoryFileRecordsCreator::processDirectory(const QDir &directory) {

    QFileInfoList fileInfos = directory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    for(int i = 0; i < fileInfos.size(); ++i) {
        QFileInfo fileInfo = fileInfos[i];

        if(fileInfo.isDir() && _fileSettingsModel.isCheckSubdirs()) {
            processDirectory(fileInfo.filePath());
        } else {
            QString extension = StringUtils::getFileExtension(fileInfo.fileName());
            if(extension == "png" || extension == "jpg" || extension == "jpeg" || extension == "gif") {
                processFile(fileInfo);
            }
        }

        if(isInterruptionRequested()) {
            return;
        }
    }
}

void DirectoryFileRecordsCreator::processFile(const QFileInfo &fileInfo) {
    FileRecord fileRecord;

    QString extPath = fileInfo.filePath();
    int index = extPath.lastIndexOf("/");
    extPath = extPath.left(index);
    extPath.replace(_fileSettingsModel.getSourcePath(), "");

    fileRecord.inputFilePath = _fileSettingsModel.getSourcePath() + extPath;
    fileRecord.inputFileName = fileInfo.fileName();
    fileRecord.outputFilePath = _fileSettingsModel.getOutputPath() + extPath;
    fileRecord.outputFileName = StringUtils::normalize(fileRecord.inputFileName);

    fileRecord = replaceFormat(fileRecord);

    _imageRecordsModel.addRecord(fileRecord);
}
