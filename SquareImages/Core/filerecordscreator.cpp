#include "filerecordscreator.h"

#include "stringutils.h"

FileRecordsCreator::FileRecordsCreator(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent) : QThread(parent),
    _imageRecordsModel(imageRecordsModel),
    _fileSettingsModel(fileSettingsModel)
{

}

FileRecord FileRecordsCreator::replaceFormat(const FileRecord &fileRecord) const {
    FileRecord result = fileRecord;

    QString ext = _fileSettingsModel.getForcedFormatExtension();
    if(!ext.isEmpty() && !result.outputFileName.endsWith(ext)) {
        result.outputFileName = StringUtils::replaceFileExtension(result.outputFileName, ext);
    }

    return result;
}
