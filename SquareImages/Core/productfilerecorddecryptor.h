#ifndef PRODUCTFILERECORDDECRYPTOR_H
#define PRODUCTFILERECORDDECRYPTOR_H


#include "filerecorddecryptor.h"

class ProductFileRecordDecryptor : public FileRecordDecryptor
{
    Q_OBJECT

public:
    explicit ProductFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileRecordSettingsModel, QObject *parent = 0);

protected:
    virtual FileRecord prepareFileRecord(const QStringList &fields) const Q_DECL_OVERRIDE;

    virtual QString getOutputFileRecordExtension(const QStringList &fields) const Q_DECL_OVERRIDE;
};

#endif // PRODUCTFILERECORDDECRYPTOR_H
