#ifndef TOPPRODUCTFILERECORDDECRYPTOR_H
#define TOPPRODUCTFILERECORDDECRYPTOR_H


#include "productfilerecorddecryptor.h"

class TopProductFileRecordDecryptor : public ProductFileRecordDecryptor
{
    Q_OBJECT

public:
    explicit TopProductFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileRecordSettingsModel, QObject *parent = 0);

    virtual FileRecord prepareFileRecord(const QStringList &fields) const Q_DECL_OVERRIDE;

    virtual FileRecord getVerifiedFileRecord(const FileRecord &fileRecord) const Q_DECL_OVERRIDE;

    virtual QString getOutputFileRecordExtension(const QStringList &fields) const Q_DECL_OVERRIDE;
};

#endif // TOPPRODUCTFILERECORDDECRYPTOR_H
