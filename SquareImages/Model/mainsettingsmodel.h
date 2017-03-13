#ifndef MAINSETTINGSMODEL_H
#define MAINSETTINGSMODEL_H

#include <QObject>

class MainSettingsModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(ConversionType conversionType READ getConversionType WRITE setConversionType NOTIFY conversionTypeChanged)

    Q_PROPERTY(QString outputPath READ getOutputPath WRITE setOutputPath NOTIFY outputPathChanged)
    Q_PROPERTY(QString sourceFile READ getSourceFile WRITE setSourceFile NOTIFY sourceFileChanged)
    Q_PROPERTY(QString sourcePath READ getSourcePath WRITE setSourcePath NOTIFY sourcePathChanged)
    Q_PROPERTY(QString listFile READ getListFile WRITE setListFile NOTIFY listFileChanged)

    Q_PROPERTY(bool checkSubdirs READ isCheckSubdirs WRITE setCheckSubdirs NOTIFY checkSubdirsChanged)
    Q_PROPERTY(bool replaceExisting READ isReplaceExisting WRITE setReplaceExisting NOTIFY replaceExistingChanged)
    Q_PROPERTY(bool normalizeNames READ isNormalizeNames WRITE setNormalizeNames NOTIFY normalizeNamesChanged)

    Q_PROPERTY(ForcedFormat forcedFormat READ getForcedFormat WRITE setForcedFormat NOTIFY forcedFormatChanged)

    Q_PROPERTY(int imageQuality READ getImageQuality WRITE setImageQuality NOTIFY imageQualityChanged)

public:
    enum ConversionType {
        ConvertSingleImage,
        ConvertDirectoryImages,
        ConvertSimpleImages,
        ConvertBrandImages,
        ConvertProductImages,
        ConvertTopProductImages
    };

    static QStringList convertsionTypeNames;

private:
    static QStringList initConvertsionTypeNames();

public:
    enum ForcedFormat {
        ForceNone,
        ForcePng,
        ForceJpg
    };

    static QStringList forcedFormatNames;

private:
    static QStringList initForcedFormatNames();

public:
    explicit MainSettingsModel(QObject *parent = 0);


    ConversionType getConversionType() const;

    QString getOutputPath() const;
    QString getSourceFile() const;
    QString getSourcePath() const;
    QString getListFile() const;

    bool isCheckSubdirs() const;
    bool isReplaceExisting() const;
    bool isNormalizeNames() const;

    ForcedFormat getForcedFormat() const;
    QString getForcedFormatExtension() const;

    int getImageQuality() const;

signals:
    void conversionTypeChanged(ConversionType conversionType);
    void conversionTypeChanged(int conversionType);

    void outputPathChanged(const QString &outputPath);
    void sourceFileChanged(const QString &sourceFile);
    void sourcePathChanged(const QString &sourcePath);
    void listFileChanged(const QString &listFile);

    void checkSubdirsChanged(bool checkSubdirs);
    void replaceExistingChanged(bool replaceExisting);
    void normalizeNamesChanged(bool normalizeNames);

    void forcedFormatChanged(ForcedFormat forcedFormat);
    void forcedFormatChanged(int forcedFormat);

    void imageQualityChanged(int imageQuality);

public slots:
    void setConversionType(ConversionType conversionType);
    void setConversionType(int conversionType);

    void setOutputPath(const QString &outputPath);
    void setSourceFile(const QString &sourceFile);
    void setSourcePath(const QString &sourcePath);
    void setListFile(const QString &listFile);

    void setCheckSubdirs(bool checkSubdirs);
    void setReplaceExisting(bool replaceExisting);
    void setNormalizeNames(bool normalizeNames);

    void setForcedFormat(ForcedFormat forcedFormat);
    void setForcedFormat(int forcedFormat);

    void setImageQuality(int imageQuality);

private:
    ConversionType _conversionType;

    QString _outputPath;
    QString _sourceFile;
    QString _sourcePath;
    QString _listFile;

    bool _checkSubdirs;
    bool _replaceExisting;
    bool _normalizeNames;

    ForcedFormat _forcedFormat;

    int _imageQuality;
};

Q_DECLARE_METATYPE(MainSettingsModel::ConversionType)
Q_DECLARE_METATYPE(MainSettingsModel::ForcedFormat)

#endif // MAINSETTINGSMODEL_H
