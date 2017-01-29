#include "productfilerecorddecryptor.h"

#include "stringutils.h"

ProductFileRecordDecryptor::ProductFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileRecordSettingsModel, QObject *parent) :
    FileRecordDecryptor(imageRecordsModel, fileRecordSettingsModel, parent)
{

}

FileRecord ProductFileRecordDecryptor::prepareFileRecord(const QStringList &fields) const {
    FileRecord result;

    if(fields.size() < 1)
        return result;

    QString fileName = fields[0];

    if(fileName.isEmpty())
        return result;

    if(fields.size() < 2) {
        result.setError(tr("Brand name is empty."));
        return result;
    }

    QString brandName = fields[1];

    if(brandName.isEmpty()) {
        result.setError(tr("Brand name is empty."));
        return result;
    }

    result.inputFilePath = _fileRecordSettingsModel.getSourcePath();
    result.inputFileName = fileName;

    return result;
}




QString ProductFileRecordDecryptor::getOutputFileRecordExtension(const QStringList &fields) const {
    QString brandName = StringUtils::normalize(fields[1]); //TODO performance - can be stored as field (only 2nd ver.)
    return "/" + brandName.left(1) + "/" + brandName;
}
