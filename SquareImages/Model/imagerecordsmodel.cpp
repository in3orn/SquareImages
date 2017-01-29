#include "imagerecordsmodel.h"

ImageRecordsModel::ImageRecordsModel(QObject *parent) : QAbstractTableModel(parent)
{
    connect(this, &ImageRecordsModel::dataChanged, this, &QAbstractItemModel::dataChanged, Qt::QueuedConnection);
}

QModelIndex ImageRecordsModel::index(int row, int column, const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return createIndex(row, column);
}

QModelIndex ImageRecordsModel::parent(const QModelIndex &child) const {
    Q_UNUSED(child);
    return QModelIndex();
}

int ImageRecordsModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return _model.size();
}

int ImageRecordsModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return Columns::Size;
}

QVariant ImageRecordsModel::data(const QModelIndex &index, int role) const {

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case Index:
            return index.row();
        case FileName:
            return _model.at(index.row()).inputFileName;
        case State:
            return _model.at(index.row()).getStatusString();
        case Error:
            return _model.at(index.row()).getError();
        default:
            return QVariant();
        }
    }

    return QVariant();
}

bool ImageRecordsModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    Q_UNUSED(index);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return true;
}

QVariant ImageRecordsModel::headerData(int section, Qt::Orientation orientation, int role) const {

    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case Index:
            return tr("Lp.");
        case FileName:
            return tr("Nazwa pliku");
        case State:
            return tr("Status");
        case Error:
            return tr("Błąd");
        default:
            return QVariant();
        }
    }

    return QVariant();
}

FileRecord ImageRecordsModel::getRecord(int indx) {
    return _model[indx];
}

void ImageRecordsModel::setRecord(int indx, const FileRecord &fileRecord) {
    _model[indx] = fileRecord;
    emit dataChanged(index(indx, 0), index(indx, Size-1));
}

void ImageRecordsModel::addRecord(const FileRecord &fileRecord) {
    beginInsertRows(QModelIndex(), _model.size(), _model.size());
    _model.append(fileRecord);
    endInsertRows();
}

void ImageRecordsModel::clear() {
    if(_model.size() > 0) {
        beginRemoveRows(QModelIndex(), 0, _model.size()-1);
        _model.clear();
        endRemoveRows();
    }
}
