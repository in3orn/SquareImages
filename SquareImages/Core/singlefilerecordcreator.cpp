#include "singlefilerecordcreator.h"

#include <QDir>

#include "stringutils.h"

SingleFileRecordCreator::SingleFileRecordCreator(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent) :
    FileRecordsCreator(imageRecordsModel, fileSettingsModel, parent)
{

}

void SingleFileRecordCreator::run() {
    processStarted();

    FileRecord fileRecord;

    QString source = _fileSettingsModel.getSourceFile();
    int index = source.lastIndexOf("/");

    QString sourcePath = source.left(index);
    QString sourceFile = source.mid(index+1);

    QDir directory(sourcePath);
    if(directory.exists(sourceFile)) {
        fileRecord.inputFilePath = sourcePath;
        fileRecord.inputFileName = sourceFile;
        fileRecord.outputFilePath = _fileSettingsModel.getOutputPath();
        fileRecord.outputFileName = StringUtils::normalize(fileRecord.inputFileName);
        fileRecord = replaceFormat(fileRecord);
    } else {
        fileRecord.setError(tr("Nie można odnaleźć pliku: %0.").arg(source));
    }

    _imageRecordsModel.addRecord(fileRecord);

    processFinished();
}
