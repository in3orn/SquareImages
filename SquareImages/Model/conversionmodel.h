#ifndef CONVERSIONMODEL_H
#define CONVERSIONMODEL_H

#include <QObject>

class ConversionModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool running READ isRunning WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(int progress READ getProgress WRITE setProgress NOTIFY progressChanged)

public:
    explicit ConversionModel(QObject *parent = 0);

    bool isRunning() const;

    int getProgress() const;

signals:
    void runningChanged(bool running);

    void progressChanged(int progress);

public slots:
    void setRunning(bool running);

    void setProgress(int progress);

private:
    bool _running;

    int _progress;
};

#endif // CONVERSIONMODEL_H
