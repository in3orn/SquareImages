#ifndef SIMPLEFILERECORDDECRYPTOR_H
#define SIMPLEFILERECORDDECRYPTOR_H

#include "filerecorddecryptor.h"

class SimpleFileRecordDecryptor : public FileRecordDecryptor
{
    Q_OBJECT

public:
    explicit SimpleFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileRecordSettingsModel, QObject *parent = 0);

    virtual QString getOutputFileRecordExtension(const QStringList &fields) const;
};

#endif // SIMPLEFILERECORDDECRYPTOR_H
