#ifndef MAINSETTINGSMODEL_H
#define MAINSETTINGSMODEL_H

#include <QObject>

class MainSettingsModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int conversionType READ getConversionType WRITE setConversionType NOTIFY conversionTypeChanged)

    Q_PROPERTY(QString outputPath READ getOutputPath WRITE setOutputPath NOTIFY outputPathChanged)
    Q_PROPERTY(QString sourceFile READ getSourceFile WRITE setSourceFile NOTIFY sourceFileChanged)
    Q_PROPERTY(QString sourcePath READ getSourcePath WRITE setSourcePath NOTIFY sourcePathChanged)
    Q_PROPERTY(QString listFile READ getListFile WRITE setListFile NOTIFY listFileChanged)

    Q_PROPERTY(bool checkSubdirs READ isCheckSubdirs WRITE setCheckSubdirs NOTIFY checkSubdirsChanged)
    Q_PROPERTY(bool replaceExisting READ isReplaceExisting WRITE setReplaceExisting NOTIFY replaceExistingChanged)

    Q_PROPERTY(int forcedFormat READ getForcedFormat WRITE setForcedFormat NOTIFY forcedFormatChanged)

public:
    enum ConversionType {
        SingleImage,
        DirectoryImages,
        SimpleImageList,
        BrandImageList,
        ProductImageList
    };

    enum ForcedFormat {
        None,
        PNG,
        JPG
    };

public:
    explicit MainSettingsModel(QObject *parent = 0);

    int getConversionType() const;

    QString getOutputPath() const;
    QString getSourceFile() const;
    QString getSourcePath() const;
    QString getListFile() const;

    bool isCheckSubdirs() const;
    bool isReplaceExisting() const;

    int getForcedFormat() const;

signals:
    void conversionTypeChanged(int conversionType);

    void outputPathChanged(const QString &outputPath);
    void sourceFileChanged(const QString &sourceFile);
    void sourcePathChanged(const QString &sourcePath);
    void listFileChanged(const QString &listFile);

    void checkSubdirsChanged(bool checkSubdirs);
    void replaceExistingChanged(bool replaceExisting);

    void forcedFormatChanged(int forcedFormat);

public slots:
    void setConversionType(int conversionType);

    void setOutputPath(const QString &outputPath);
    void setSourceFile(const QString &sourceFile);
    void setSourcePath(const QString &sourcePath);
    void setListFile(const QString &listFile);

    void setCheckSubdirs(bool checkSubdirs);
    void setReplaceExisting(bool replaceExisting);

    void setForcedFormat(int forcedFormat);

private:
    int _conversionType;

    QString _outputPath;
    QString _sourceFile;
    QString _sourcePath;
    QString _listFile;

    bool _checkSubdirs;
    bool _replaceExisting;

    ForcedFormat _forcedFormat;
};

#endif // MAINSETTINGSMODEL_H