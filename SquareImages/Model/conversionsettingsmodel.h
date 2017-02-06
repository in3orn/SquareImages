#ifndef CONVERSIONSETTINGSMODEL_H
#define CONVERSIONSETTINGSMODEL_H

#include <QObject>
#include <QColor>
#include <QFont>

class ConversionSettingsModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ConverterType converterType READ getConverterType WRITE setConverterType NOTIFY converterTypeChanged)

    Q_PROPERTY(HorizontalAlignment horizontalAlignment READ getHorizontalAlignment WRITE setHorizontalAlignment NOTIFY horizontalAlignmentChanged)
    Q_PROPERTY(VerticalAlignment verticalAlignment READ getVerticalAlignment WRITE setVerticalAlignment NOTIFY verticalAlignmentChanged)

    Q_PROPERTY(int xRatio READ getXRatio WRITE setXRatio NOTIFY xRatioChanged)
    Q_PROPERTY(int yRatio READ getYRatio WRITE setYRatio NOTIFY yRatioChanged)

    Q_PROPERTY(int margin READ getMargin WRITE setMargin NOTIFY marginChanged)

    Q_PROPERTY(int textSize READ getTextSize WRITE setTextSize NOTIFY textSizeChanged)

    Q_PROPERTY(int alphaTolerance READ getAlphaTolerance WRITE setAlphaTolerance NOTIFY alphaToleranceChanged)
    Q_PROPERTY(int colorTolerance READ getColorTolerance WRITE setColorTolerance NOTIFY colorToleranceChanged)

    Q_PROPERTY(int maxScaleValue READ getMaxScaleValue WRITE setMaxScaleValue NOTIFY maxScaleValueChanged)
    Q_PROPERTY(int minScaleValue READ getMinScaleValue WRITE setMinScaleValue NOTIFY minScaleValueChanged)

    Q_PROPERTY(bool clearColor READ isClearColor WRITE setClearColor NOTIFY clearColorChanged)

    Q_PROPERTY(QColor backgroundColor READ getBackgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor NOTIFY textColorChanged)

    Q_PROPERTY(QFont textFont READ getTextFont WRITE setTextFont NOTIFY textFontChanged)

public:
    enum ConverterType {
        SquareImageConverter,
        CropImageConverter,
        TextImageConverter,
        ScaleImageConverter
    };

    static QStringList converterTypeNames;

private:
    static QStringList initConverterTypeNames();

public:
    enum HorizontalAlignment {
        Left,
        HCenter,
        Right
    };

    static QStringList horizontalAlignmentNames;

private:
    static QStringList initHorizontalAlignmentNames();

public:
    enum VerticalAlignment {
        Top,
        VCenter,
        Bottom
    };

    static QStringList verticalAlignmentNames;

private:
    static QStringList initVerticalAlignmentNames();

public:
    enum MaxScaleStrategy {
        MaxScaleNone,
        MaxScaleWidth,
        MaxScaleHeight
    };

    static QStringList maxScaleStrategyNames;

private:
    static QStringList initMaxScaleStrategyNames();

public:
    enum MinScaleStrategy {
        MinScaleNone,
        MinScaleWidth,
        MinScaleHeight
    };

    static QStringList minScaleStrategyNames;

private:
    static QStringList initMinScaleStrategyNames();

public:
    explicit ConversionSettingsModel(QObject *parent = 0);

    ConverterType getConverterType() const;

    HorizontalAlignment getHorizontalAlignment() const;
    VerticalAlignment getVerticalAlignment() const;

    MaxScaleStrategy getMaxScaleStrategy() const;
    MinScaleStrategy getMinScaleStrategy() const;

    int getXRatio() const;
    int getYRatio() const;

    int getMargin() const;

    int getTextSize() const;

    int getAlphaTolerance() const;
    int getColorTolerance() const;

    int getMaxScaleValue() const;
    int getMinScaleValue() const;

    bool isClearColor() const;

    QColor getBackgroundColor() const;
    QColor getTextColor() const;

    QFont getTextFont() const;

signals:
    void converterTypeChanged(ConverterType converterType);
    void converterTypeChanged(int converterType);

    void horizontalAlignmentChanged(HorizontalAlignment horizontalAlignment);
    void horizontalAlignmentChanged(int horizontalAlignment);

    void verticalAlignmentChanged(VerticalAlignment verticalAlignment);
    void verticalAlignmentChanged(int verticalAlignment);

    void maxScaleStrategyChanged(MaxScaleStrategy maxScaleStrategy);
    void maxScaleStrategyChanged(int maxScaleStrategy);

    void minScaleStrategyChanged(MinScaleStrategy minScaleStrategy);
    void minScaleStrategyChanged(int minScaleStrategy);

    void xRatioChanged(int xRatio);
    void yRatioChanged(int yRatio);

    void marginChanged(int margin);

    void textSizeChanged(int textSize);

    void alphaToleranceChanged(int alphaTolerance);
    void colorToleranceChanged(int colorTolerance);

    void maxScaleValueChanged(int maxScaleValue);
    void minScaleValueChanged(int minScaleValue);

    void clearColorChanged(bool clearColor);

    void backgroundColorChanged(const QColor &backgroundColor);
    void textColorChanged(const QColor &textColor);

    void textFontChanged(const QFont &textFont);

public slots:
    void setConverterType(ConverterType converterType);
    void setConverterType(int converterType);

    void setHorizontalAlignment(HorizontalAlignment horizontalAlignment);
    void setHorizontalAlignment(int horizontalAlignment);

    void setVerticalAlignment(VerticalAlignment verticalAlignment);
    void setVerticalAlignment(int verticalAlignment);

    void setMaxScaleStrategy(MaxScaleStrategy maxScaleStrategy);
    void setMaxScaleStrategy(int maxScaleStrategy);

    void setMinScaleStrategy(MinScaleStrategy minScaleStrategy);
    void setMinScaleStrategy(int minScaleStrategy);

    void setXRatio(int xRatio);
    void setYRatio(int yRatio);

    void setMargin(int margin);

    void setTextSize(int textSize);

    void setAlphaTolerance(int alphaTolerance);
    void setColorTolerance(int colorTolerance);

    void setMaxScaleValue(int maxScaleValue);
    void setMinScaleValue(int minScaleValue);

    void setClearColor(bool clearColor);

    void setBackgroundColor(const QColor &backgroundColor);
    void setTextColor(const QColor &textColor);

    void setTextFont(const QFont &textFont);

private:
    ConverterType _converterType;

    HorizontalAlignment _horizontalAlignment;
    VerticalAlignment _verticalAlignment;

    MaxScaleStrategy _maxScaleStrategy;
    MinScaleStrategy _minScaleStrategy;

    int _xRatio;
    int _yRatio;

    int _margin;

    int _textSize;

    int _alphaTolerance;
    int _colorTolerance;

    int _maxScaleValue;
    int _minScaleValue;

    bool _clearColor;

    QColor _backgroundColor;
    QColor _textColor;

    QFont _textFont;
};

#endif // CONVERSIONSETTINGSMODEL_H
