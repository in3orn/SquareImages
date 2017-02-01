#include "imagerecordscontroller.h"

#include <QHeaderView>

#include "Delegate/imagerecorddelegate.h"

ImageRecordsController::ImageRecordsController(ImageRecordsModel &imageRecordsModel, QObject *parent) : QObject(parent),
    _imageRecordsModel(imageRecordsModel)
{

}

void ImageRecordsController::connectImageRecords(QTableView *view) {
    view->setModel(&_imageRecordsModel);

    ImageRecordDelegate *delegate = new ImageRecordDelegate(view);
    view->setItemDelegate(delegate);

    view->setColumnWidth(ImageRecordsModel::Index, 25);
    view->setColumnWidth(ImageRecordsModel::Name, 150);
    view->setColumnWidth(ImageRecordsModel::State, 150);

    view->horizontalHeader()->setSectionResizeMode(ImageRecordsModel::Error, QHeaderView::Stretch);
}
