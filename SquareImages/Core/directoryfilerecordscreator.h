#ifndef DIRECTORYFILERECORDSCREATOR_H
#define DIRECTORYFILERECORDSCREATOR_H

#include "filerecordscreator.h"

#include <QDir>

class DirectoryFileRecordsCreator : public FileRecordsCreator
{
    Q_OBJECT

public:
    explicit DirectoryFileRecordsCreator(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent = 0);

protected:
    virtual void run();

    void processDirectory(const QDir &directory);

    void processFile(const QFileInfo &fileInfo);
};

#endif // DIRECTORYFILERECORDSCREATOR_H
