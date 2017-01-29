#include "singleimageconverter.h"

SingleImageConverter::SingleImageConverter(ImageConverter *imageConverter, QObject *parent) :
    ImageListConverter(imageConverter, parent)
{

}

QList<FilePaths> SingleImageConverter::getFilePathsList() {
    QList<FilePaths> filePathsList;

//    FilePaths filePaths;

//    QString sourcePath = _mainSettingsModel->getSourceFile();

//    int index = sourcePath.lastIndexOf("/");
//    if(index >= 0) {
//        params.inputFilePath = sourcePath.left(index);
//        params.inputFileName = sourcePath.mid(index+1);
//    } else {
//        params.inputFileName = sourcePath;
//    }

//    params.outputFilePath = _mainSettingsModel->getOutputPath();
//    params.outputFileName = StringUtils::normalize(params.inputFileName);

//    result << params;

    return filePathsList;
}
