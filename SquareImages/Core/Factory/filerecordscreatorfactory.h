#ifndef FILERECORDSCREATORFACTORY_H
#define FILERECORDSCREATORFACTORY_H

#include "../filerecordscreator.h"

class FileRecordsCreatorFactory
{
public:
    static FileRecordsCreatorFactory &getInstance();

    FileRecordsCreator *create(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel);
};

#endif // FILERECORDSCREATORFACTORY_H
