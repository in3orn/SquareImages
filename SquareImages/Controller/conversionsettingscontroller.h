#ifndef CONVERSIONSETTINGSCONTROLLER_H
#define CONVERSIONSETTINGSCONTROLLER_H

#include <QObject>

#include "Model/conversionmodel.h"
#include "Model/conversionsettingsmodel.h"

class QComboBox;
class QSpinBox;
class QSlider;
class QGraphicsView;
class QPushButton;
class QCheckBox;
class QLineEdit;

class ConversionSettingsController : public QObject
{
    Q_OBJECT

public:
    explicit ConversionSettingsController(QObject *parent = 0);

    ConversionModel *getConversionModel() const;
    ConversionSettingsModel *getConversionSettingsModel() const;

    void setConversionModel(ConversionModel *conversionModel);
    void setConversionSettingsModel(ConversionSettingsModel *conversionSettingsModel);


    void connectConverterTypeComboBox(QComboBox *widget);

    void connectHorizontalAlignmentComboBox(QComboBox *widget);
    void connectVerticalAlignmentComboBox(QComboBox *widget);

    void connectMaxScaleStrategyComboBox(QComboBox *widget);
    void connectMaxScaleValueSpinBox(QSpinBox *widget);

    void connectMinScaleStrategyComboBox(QComboBox *widget);
    void connectMinScaleValueSpinBox(QSpinBox *widget);

    void connectXRatioSpinBox(QSpinBox *widget);
    void connectYRatioSpinBox(QSpinBox *widget);

    void connectMarginSpinBox(QSpinBox *widget);
    void connectMarginSlider(QSlider *widget);

    void connectTextSizeSpinBox(QSpinBox *widget);
    void connectTextSizeSlider(QSlider *widget);

    void connectAlphaToleranceSpinBox(QSpinBox *widget);
    void connectAlphaToleranceSlider(QSlider *widget);

    void connectColorToleranceSpinBox(QSpinBox *widget);
    void connectColorToleranceSlider(QSlider *widget);

    void connectClearColorCheckBox(QCheckBox *widget);

    void connectBackgroundColorView(QGraphicsView *widget);
    void connectBackgroundColorButton(QPushButton *widget);

    void connectTextColorView(QGraphicsView *widget);
    void connectTextColorButton(QPushButton *widget);

    void connectTextFontLineEdit(QLineEdit *widget);
    void connectTextFontButton(QPushButton *widget);

protected:
    void selectBackgroundColor();
    void setBackgroundColorViewColor(const QColor &backgroundColor);

    void selectTextColor();
    void setTextColorViewColor(const QColor &textColor);

    void selectTextFont();
    void setTextFontLineEditFont(const QFont &textFont);

signals:

public slots:
    void refreshWidgets();

protected:
    void refreshConverterTypeComboBox();

    void refreshHorizontalAlignmentComboBox();
    void refreshVerticalAlignmentComboBox();

    void refreshMaxScaleStrategyComboBox();
    void refreshMaxScaleValueSpinBox();

    void refreshMinScaleStrategyComboBox();
    void refreshMinScaleValueSpinBox();

    void refreshXRatioSpinBox();
    void refreshYRatioSpinBox();

    void refreshMarginSpinBox();
    void refreshMarginSlider();

    void refreshTextSizeSpinBox();
    void refreshTextSizeSlider();

    void refreshAlphaToleranceSpinBox();
    void refreshAlphaToleranceSlider();

    void refreshColorToleranceSpinBox();
    void refreshColorToleranceSlider();

    void refreshClearColorCheckBox();

    void refreshBackgroundColorView();
    void refreshBackgroundColorButton();

    void refreshTextColorView();
    void refreshTextColorButton();

    void refreshTextFontLineEdit();
    void refreshTextFontButton();

private:
    ConversionModel *_conversionModel;
    ConversionSettingsModel *_conversionSettingsModel;


    QComboBox *_converterTypeComboBox;

    QComboBox *_horizontalAlignmentComboBox;
    QComboBox *_verticalAlignmentComboBox;

    QComboBox *_maxScaleStrategyComboBox;
    QSpinBox *_maxScaleValueSpinBox;

    QComboBox *_minScaleStrategyComboBox;
    QSpinBox *_minScaleValueSpinBox;

    QSpinBox *_xRatioSpinBox;
    QSpinBox *_yRatioSpinBox;

    QSpinBox *_marginSpinBox;
    QSlider *_marginSlider;

    QSpinBox *_textSizeSpinBox;
    QSlider *_textSizeSlider;

    QCheckBox *_clearColorCheckBox;

    QSpinBox *_alphaToleranceSpinBox;
    QSlider *_alphaToleranceSlider;

    QSpinBox *_colorToleranceSpinBox;
    QSlider *_colorToleranceSlider;

    QGraphicsView *_backgroundColorView;
    QPushButton *_backgroundColorButton;

    QGraphicsView *_textColorView;
    QPushButton *_textColorButton;

    QLineEdit *_textFontLineEdit;
    QPushButton *_textFontButton;
};

#endif // CONVERSIONSETTINGSCONTROLLER_H
