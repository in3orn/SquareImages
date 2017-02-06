#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <QString>

class StringUtils
{
protected:
    StringUtils();

public:
    static QString normalizeName(const QString &string);

    static QString normalizePath(const QString &string);

    static QString replaceSpecialCharacters(const QString &string);

    static QString removeSpecialCharacters(const QString &string);

    static QString removeFileName(const QString &filePath);

    static QString getFileName(const QString &filePath);

    static QString removeFileExtension(const QString &filePath);

    static QString getFileExtension(const QString &filePath);

    static QString replaceFileExtension(const QString &filePath, const QString &newExtension);
};

#endif // STRINGUTILS_H
