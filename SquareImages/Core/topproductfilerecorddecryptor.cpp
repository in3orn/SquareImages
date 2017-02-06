#include "topproductfilerecorddecryptor.h"

#include "stringutils.h"

TopProductFileRecordDecryptor::TopProductFileRecordDecryptor(
        ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileRecordSettingsModel, QObject *parent) :
    ProductFileRecordDecryptor(imageRecordsModel, fileRecordSettingsModel, parent)
{

}

FileRecord TopProductFileRecordDecryptor::prepareFileRecord(const QStringList &fields) const {
    FileRecord result = ProductFileRecordDecryptor::prepareFileRecord(fields);

    if(!result.name.isEmpty() && result.getError().isEmpty())
    {
        result.inputFilePath = StringUtils::removeFileName(_fileRecordSettingsModel.getSourceFile());
        result.inputFileName = StringUtils::getFileName(_fileRecordSettingsModel.getSourceFile());
        result.outputFileName = StringUtils::normalizeName(result.inputFileName);

        result = replaceFormat(result);
    }

    return result;
}

FileRecord TopProductFileRecordDecryptor::getVerifiedFileRecord(const FileRecord &fileRecord) const {
    return fileRecord;
}
