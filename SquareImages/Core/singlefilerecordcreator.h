#ifndef SINGLEFILERECORDCREATOR_H
#define SINGLEFILERECORDCREATOR_H

#include "filerecordscreator.h"

class SingleFileRecordCreator : public FileRecordsCreator
{
    Q_OBJECT

public:
    explicit SingleFileRecordCreator(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent = 0);

protected:
    virtual void run();
};

#endif // SINGLEFILERECORDCREATOR_H
