#include "filerecordscreator.h"

#include "stringutils.h"

FileRecordsCreator::FileRecordsCreator(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel, QObject *parent) : QThread(parent),
    _imageRecordsModel(imageRecordsModel),
    _fileSettingsModel(fileSettingsModel)
{

}

FileRecord FileRecordsCreator::replaceFormat(const FileRecord &fileRecord) const {
    FileRecord result = fileRecord;

    //TODO should be done by FileRecordFormatReplacer??
    switch(_fileSettingsModel.getForcedFormat()) {
    case MainSettingsModel::ForcedFormat::ForceJpg:
        result.outputFileName = StringUtils::replaceFileExtension(result.outputFileName, "jpg");
        break;
    case MainSettingsModel::ForcedFormat::ForcePng:
        result.outputFileName = StringUtils::replaceFileExtension(result.outputFileName, "png");
        break;
    }

    return result;
}
