#ifndef FILERECORD_H
#define FILERECORD_H

#include <QString>

class FileRecord
{
public:
    enum Status {
        Waiting,
        Omitted,
        Success,
        Error
    };

    FileRecord();

    void setError(const QString &error);
    QString getError() const;

    QString getStatusString() const;

    void finish();
    void omit();

public:
    QString name;

    QString inputFilePath;
    QString inputFileName;

    QString outputFilePath;
    QString outputFileName;

private:
    QString _error;

    Status _status;
};

#endif // FILERECORD_H
