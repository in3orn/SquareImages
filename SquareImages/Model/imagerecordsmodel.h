#ifndef IMAGERECORDSMODEL_H
#define IMAGERECORDSMODEL_H

#include <QAbstractTableModel>
#include <QList>

#include "../Core/filerecord.h"

class ImageRecordsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum Columns {
        Index = 0,
        FileName,
        State,
        Error,
        Size
    };

public:
    explicit ImageRecordsModel(QObject *parent = 0);


    Q_INVOKABLE virtual QModelIndex index(int row, int column,
                              const QModelIndex &parent = QModelIndex()) const;
    Q_INVOKABLE virtual QModelIndex parent(const QModelIndex &child) const;

    Q_INVOKABLE virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    Q_INVOKABLE virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

    Q_INVOKABLE virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Q_INVOKABLE virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    Q_INVOKABLE virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    FileRecord getRecord(int indx);
    void setRecord(int indx, const FileRecord &fileRecord);
    void addRecord(const FileRecord &fileRecord);

    void clear();

signals:
    void dataChanged(QModelIndex const topLeft, QModelIndex const bottomRight, QVector<int> const roles = QVector<int>());

private:
    QList<FileRecord> _model;
};

#endif // IMAGERECORDSMODEL_H
