#ifndef CONVERSIONSETTINGSCONTROLLER_H
#define CONVERSIONSETTINGSCONTROLLER_H

#include <QObject>

#include <QSpinBox>
#include <QSlider>
#include <QGraphicsView>
#include <QPushButton>
#include <QCheckBox>

#include "Model/conversionmodel.h"
#include "Model/conversionsettingsmodel.h"

class ConversionSettingsController : public QObject
{
    Q_OBJECT

public:
    explicit ConversionSettingsController(QObject *parent = 0);

    ConversionModel *getConversionModel() const;
    ConversionSettingsModel *getConversionSettingsModel() const;

    void setConversionModel(ConversionModel *conversionModel);
    void setConversionSettingsModel(ConversionSettingsModel *conversionSettingsModel);


    void connectXRatioSpinBox(QSpinBox *widget);
    void connectYRatioSpinBox(QSpinBox *widget);

    void connectMarginSpinBox(QSpinBox *widget);
    void connectMarginSlider(QSlider *widget);

    void connectAlphaToleranceSpinBox(QSpinBox *widget);
    void connectAlphaToleranceSlider(QSlider *widget);

    void connectColorToleranceSpinBox(QSpinBox *widget);
    void connectColorToleranceSlider(QSlider *widget);

    void connectColorView(QGraphicsView *widget);
    void connectColorButton(QPushButton *widget);

    void connectClearColorCheckBox(QCheckBox *widget);

    void selectColor();

    void setColorViewColor(const QColor &color);

signals:

public slots:
    void refreshWidgets();

protected:
    void refreshXRadioSpinBox();
    void refreshYRadioSpinBox();

    void refreshMarginSpinBox();
    void refreshMarginSlider();

    void refreshAlphaToleranceSpinBox();
    void refreshAlphaToleranceSlider();

    void refreshColorToleranceSpinBox();
    void refreshColorToleranceSlider();

    void refreshColorView();
    void refreshColorButton();

    void refreshClearColorCheckBox();

private:
    ConversionModel *_conversionModel;
    ConversionSettingsModel *_conversionSettingsModel;

    QSpinBox *_xRatioSpinBox;
    QSpinBox *_yRatioSpinBox;

    QSpinBox *_marginSpinBox;
    QSlider *_marginSlider;

    QSpinBox *_alphaToleranceSpinBox;
    QSlider *_alphaToleranceSlider;

    QSpinBox *_colorToleranceSpinBox;
    QSlider *_colorToleranceSlider;

    QGraphicsView *_colorView;
    QPushButton *_colorButton;

    QCheckBox *_clearColorCheckBox;
};

#endif // CONVERSIONSETTINGSCONTROLLER_H
