#ifndef FILERECORDDECRYPTOR_H
#define FILERECORDDECRYPTOR_H

#include <QObject>
#include <QString>

#include <QDir>

#include "filerecordscreator.h"

class FileRecordDecryptor : public FileRecordsCreator
{
    Q_OBJECT

public:
    FileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent = 0);


    virtual FileRecord decryptFileRecord(const QString &string) const;


protected:
    virtual FileRecord prepareFileRecord(const QStringList &fields) const;

    virtual FileRecord getVerifiedFileRecord(const FileRecord &fileRecord) const;

    virtual FileRecord extendFileRecord(const FileRecord &fileRecord, const QStringList &fields) const;



    virtual FileRecord getFileRecord(const QDir &directory, const QString &searchedFileName) const;

    virtual FileRecord initFileRecord(const QFileInfo &fileInfo, const QString &normalizedName) const;

    virtual QString getOutputFileRecordExtension(const QStringList &fields) const;

protected:
    MainSettingsModel &_fileRecordSettingsModel;
};

#endif // FILERECORDDECRYPTOR_H
