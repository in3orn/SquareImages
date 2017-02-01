#ifndef IMAGERECORDDELEGATE_H
#define IMAGERECORDDELEGATE_H

#include <QStyledItemDelegate>

class ImageRecordDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    explicit ImageRecordDelegate(QObject *parent = 0);

protected:
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const Q_DECL_OVERRIDE;
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const Q_DECL_OVERRIDE;
};

#endif // IMAGERECORDDELEGATE_H
