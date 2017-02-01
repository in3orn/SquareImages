#include "filerecorddecryptorfactory.h"

#include "../simplefilerecorddecryptor.h"
#include "../brandfilerecorddecryptor.h"
#include "../productfilerecorddecryptor.h"
#include "../topproductfilerecorddecryptor.h"


FileRecordDecryptorFactory &FileRecordDecryptorFactory::getInstance() {
    static FileRecordDecryptorFactory factory;
    return factory;
}

FileRecordDecryptor *FileRecordDecryptorFactory::createFileRecordDecryptor(ImageRecordsModel &imageRecordsModel, MainSettingsModel &fileSettingsModel) const {

    switch(fileSettingsModel.getConversionType()) {
    case MainSettingsModel::ConvertSimpleImages:
        return new SimpleFileRecordDecryptor(imageRecordsModel, fileSettingsModel);
    case MainSettingsModel::ConvertBrandImages:
        return new BrandFileRecordDecryptor(imageRecordsModel, fileSettingsModel);
    case MainSettingsModel::ConvertProductImages:
        return new ProductFileRecordDecryptor(imageRecordsModel, fileSettingsModel);
    case MainSettingsModel::ConvertTopProductImages:
        return new TopProductFileRecordDecryptor(imageRecordsModel, fileSettingsModel);
    default:
        return Q_NULLPTR;
    }
}
