#ifndef FILERECORDSDECRYPTOR_H
#define FILERECORDSDECRYPTOR_H


#include "filerecordscreator.h"

#include "filerecorddecryptor.h"

class FileRecordsDecryptor : public FileRecordsCreator
{
    Q_OBJECT

public:
    FileRecordsDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent = 0);

    virtual ~FileRecordsDecryptor();


    FileRecordDecryptor *getFileRecordDecryptor() const;
    void setFileRecordDecryptor(FileRecordDecryptor *fileRecordDecryptor);

protected:
    virtual void run();

private:
    FileRecordDecryptor *_fileRecordDecryptor;
};

#endif // FILERECORDSDECRYPTOR_H
