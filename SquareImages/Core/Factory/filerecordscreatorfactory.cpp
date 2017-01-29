#include "filerecordscreatorfactory.h"

#include "../singlefilerecordcreator.h"
#include "../directoryfilerecordscreator.h"
#include "../filerecordsdecryptor.h"

#include "filerecorddecryptorfactory.h"

FileRecordsCreatorFactory &FileRecordsCreatorFactory::getInstance() {
    static FileRecordsCreatorFactory factory;
    return factory;
}

FileRecordsCreator *FileRecordsCreatorFactory::create(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel) {

    switch (fileSettingsModel.getConversionType()) {
    case 0:
        return new SingleFileRecordCreator(imageRecordsModel, fileSettingsModel);
    case 1:
        return new DirectoryFileRecordsCreator(imageRecordsModel, fileSettingsModel);
    default:
        FileRecordsDecryptor *fileRecordsDecryptor = new FileRecordsDecryptor(imageRecordsModel, fileSettingsModel);
        FileRecordDecryptor *fileRecordDecryptor = FileRecordDecryptorFactory::getInstance().createFileRecordDecryptor(imageRecordsModel, fileSettingsModel);
        fileRecordsDecryptor->setFileRecordDecryptor(fileRecordDecryptor);

        return fileRecordsDecryptor;
    }
}
