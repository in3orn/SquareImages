#ifndef FILERECORDDECRYPTORFACTORY_H
#define FILERECORDDECRYPTORFACTORY_H

#include "../filerecorddecryptor.h"

class FileRecordDecryptorFactory
{
public:
    static FileRecordDecryptorFactory &getInstance();

public:
    FileRecordDecryptor *createFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel) const;
};

#endif // FILERECORDDECRYPTORFACTORY_H
