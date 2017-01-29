#include "filerecorddecryptorfactory.h"

#include "../simplefilerecorddecryptor.h"
#include "../brandfilerecorddecryptor.h"
#include "../productfilerecorddecryptor.h"


FileRecordDecryptorFactory &FileRecordDecryptorFactory::getInstance() {
    static FileRecordDecryptorFactory factory;
    return factory;
}

FileRecordDecryptor *FileRecordDecryptorFactory::createFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel) const {

    switch(fileSettingsModel.getConversionType()) {
    case 2:
        return new SimpleFileRecordDecryptor(imageRecordsModel, fileSettingsModel);
    case 3:
        return new BrandFileRecordDecryptor(imageRecordsModel, fileSettingsModel);
    case 4:
        return new ProductFileRecordDecryptor(imageRecordsModel, fileSettingsModel);
    default:
        return 0;
    }
}
