#ifndef IMAGERECORDSCONTROLLER_H
#define IMAGERECORDSCONTROLLER_H

#include <QObject>

#include <QTableView>

#include "Model/imagerecordsmodel.h"

class ImageRecordsController : public QObject
{
    Q_OBJECT

public:
    explicit ImageRecordsController(ImageRecordsModel &_imageRecordsModel, QObject *parent = 0);

    void connectImageRecords(QTableView *view);

private:
    ImageRecordsModel &_imageRecordsModel;
};

#endif // IMAGERECORDSCONTROLLER_H
