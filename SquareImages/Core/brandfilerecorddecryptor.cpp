#include "brandfilerecorddecryptor.h"

#include "stringutils.h"

BrandFileRecordDecryptor::BrandFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileRecordSettingsModel, QObject *parent) :
    FileRecordDecryptor(imageRecordsModel, fileRecordSettingsModel, parent)
{

}

QString BrandFileRecordDecryptor::getOutputFileRecordExtension(const QStringList &fields) const {
    QString brandName = StringUtils::normalize(fields[0]); //TODO performance - can be stored as field (only 2nd ver.)
    return "/" + brandName.left(1);
}
