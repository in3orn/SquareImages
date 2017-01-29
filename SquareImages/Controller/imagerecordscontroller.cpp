#include "imagerecordscontroller.h"

#include <QHeaderView>

ImageRecordsController::ImageRecordsController(ImageRecordsModel &imageRecordsModel, QObject *parent) : QObject(parent),
    _imageRecordsModel(imageRecordsModel)
{

}

void ImageRecordsController::connectImageRecords(QTableView *view) {
    view->setModel(&_imageRecordsModel);

    view->setColumnWidth(ImageRecordsModel::Index, 40);

    for (int i = 1; i < view->horizontalHeader()->count(); ++i)
    {
        view->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}
