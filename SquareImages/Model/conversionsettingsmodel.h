#ifndef CONVERSIONSETTINGSMODEL_H
#define CONVERSIONSETTINGSMODEL_H

#include <QObject>
#include <QColor>

class ConversionSettingsModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int xRatio READ getXRatio WRITE setXRatio NOTIFY xRatioChanged)
    Q_PROPERTY(int yRatio READ getYRatio WRITE setYRatio NOTIFY yRatioChanged)

    Q_PROPERTY(int margin READ getMargin WRITE setMargin NOTIFY marginChanged)

    Q_PROPERTY(int alphaTolerance READ getAlphaTolerance WRITE setAlphaTolerance NOTIFY alphaToleranceChanged)
    Q_PROPERTY(int colorTolerance READ getColorTolerance WRITE setColorTolerance NOTIFY colorToleranceChanged)

    Q_PROPERTY(QColor color READ getColor WRITE setColor NOTIFY colorChanged)

    Q_PROPERTY(bool clearColor READ isClearColor WRITE setClearColor NOTIFY clearColorChanged)

public:
    explicit ConversionSettingsModel(QObject *parent = 0);

    int getXRatio() const;
    int getYRatio() const;

    int getMargin() const;

    int getAlphaTolerance() const;
    int getColorTolerance() const;

    QColor getColor() const;

    bool isClearColor() const;

signals:
    void xRatioChanged(int xRatio);
    void yRatioChanged(int yRatio);

    void marginChanged(int margin);

    void alphaToleranceChanged(int alphaTolerance);
    void colorToleranceChanged(int colorTolerance);

    void colorChanged(QColor color);

    void clearColorChanged(bool clearColor);

public slots:
    void setXRatio(int xRatio);
    void setYRatio(int yRatio);

    void setMargin(int margin);

    void setAlphaTolerance(int alphaTolerance);
    void setColorTolerance(int colorTolerance);

    void setColor(const QColor &color);

    void setClearColor(bool clearColor);

private:
    int _xRatio;
    int _yRatio;

    int _margin;

    int _alphaTolerance;
    int _colorTolerance;

    QColor _color;

    bool _clearColor;
};

#endif // CONVERSIONSETTINGSMODEL_H
