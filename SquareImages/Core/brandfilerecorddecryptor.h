#ifndef BRANDFILERECORDDECRYPTOR_H
#define BRANDFILERECORDDECRYPTOR_H

#include "filerecorddecryptor.h"

class BrandFileRecordDecryptor : public FileRecordDecryptor
{
    Q_OBJECT

public:
    explicit BrandFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileRecordSettingsModel, QObject *parent = 0);

protected:
    virtual QString getOutputFileRecordExtension(const QStringList &fields) const;
};

#endif // BRANDFILERECORDDECRYPTOR_H
