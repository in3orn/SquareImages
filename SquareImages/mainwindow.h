#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QStringListModel>
#include <QDataWidgetMapper>

#include "Model/conversionmodel.h"
#include "Model/conversionsettingsmodel.h"
#include "Model/mainsettingsmodel.h"
#include "Model/imagerecordsmodel.h"

#include "Controller/conversioncontroller.h"
#include "Controller/conversionsettingscontroller.h"
#include "Controller/mainsettingscontroller.h"
#include "Controller/imagerecordscontroller.h"

#include "Core/imagesconverter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

private:
    void initWidgets();

    void initControllers();
    void initConversionController();
    void initConversionSettingsController();
    void initMainSettingsController();
    void initImageRecordsController();

private:
    Ui::MainWindow *ui;

    ConversionModel _conversionModel;
    ConversionSettingsModel _conversionSettingsModel;
    MainSettingsModel _mainSettingsModel;
    ImageRecordsModel _imageRecordsModel;

    ConversionController _conversionController;
    ConversionSettingsController _conversionSettingsController;
    MainSettingsController *_mainSettingsController;
    ImageRecordsController *_imageRecordsController;
};

#endif // MAINWINDOW_H
