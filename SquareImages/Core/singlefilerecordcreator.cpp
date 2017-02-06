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

    fileRecord.name = StringUtils::removeFileExtension(sourceFile);

    QDir directory(sourcePath);
    if(directory.exists(sourceFile)) {
        fileRecord.inputFilePath = sourcePath;
        fileRecord.inputFileName = sourceFile;
        fileRecord.outputFilePath = _fileSettingsModel.getOutputPath();
        fileRecord.outputFileName = StringUtils::normalizeName(fileRecord.inputFileName);

        fileRecord = replaceFormat(fileRecord);
    } else {
        fileRecord.setError(tr("Nie można odnaleźć pliku: <b>%0</b> w ścieżce: <br><b>%2</b>").
                            arg(sourceFile, sourcePath));
    }

    _imageRecordsModel.addRecord(fileRecord);

    processFinished();
}
