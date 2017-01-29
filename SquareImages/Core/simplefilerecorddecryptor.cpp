#include "simplefilerecorddecryptor.h"

#include "stringutils.h"

SimpleFileRecordDecryptor::SimpleFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileRecordSettingsModel, QObject *parent) :
    FileRecordDecryptor(imageRecordsModel, fileRecordSettingsModel, parent)
{

}

QString SimpleFileRecordDecryptor::getOutputFileRecordExtension(const QStringList &fields) const {
    QString result = "";

    for(int i = 1; i < fields.size(); i++) {
        QString field = fields[i];
        if(!field.isEmpty()) {
            result += "/" + field.trimmed();
        }
    }

    return StringUtils::normalize(result);
}
