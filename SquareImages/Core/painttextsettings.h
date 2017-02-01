#ifndef PAINTTEXTSETTINGS_H
#define PAINTTEXTSETTINGS_H

#include <QPen>
#include <QFont>
#include <QRect>

class PaintTextSettings
{
public:
    QPen pen;
    QFont font;
    QRect rect;
    QString text;
    Qt::Alignment alignment;
};

#endif // PAINTTEXTSETTINGS_H
