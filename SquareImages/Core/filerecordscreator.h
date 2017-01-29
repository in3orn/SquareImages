#ifndef FILERECORDSCREATOR_H
#define FILERECORDSCREATOR_H

#include <QThread>

#include "Model/imagerecordsmodel.h"
#include "Model/mainsettingsmodel.h"

class FileRecordsCreator : public QThread
{
    Q_OBJECT

public:
    explicit FileRecordsCreator(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent = 0);

protected:
    FileRecord replaceFormat(const FileRecord &fileRecord) const;

signals:
    void processStarted();
    void processCanceled();
    void processFinished();

    void progressChanged(double progress);

    void errorReported(const QString &errorMessage);

protected:
    ImageRecordsModel &_imageRecordsModel;
    MainSettingsModel &_fileSettingsModel;
};

#endif // FILERECORDSCREATOR_H
