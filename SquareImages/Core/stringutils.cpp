#include "stringutils.h"

#include <QRegularExpression>

StringUtils::StringUtils()
{

}

QString StringUtils::normalize(const QString &string) {
    QString result = string.trimmed();

    result.replace(QRegularExpression("[&\\s]"), "-");

    result.replace(QRegularExpression("[ÀÁÂÃÄÅĀĂĄ]"), "A");
    result.replace(QRegularExpression("[Æ]"), "Ae");
    result.replace(QRegularExpression("[ÇĆĈČ]"), "C");
    result.replace(QRegularExpression("[ÈÉÊËĒĚĘ]"), "E");
    result.replace(QRegularExpression("[ÌÍÎÏ]"), "I");
    result.replace(QRegularExpression("[Ł]"), "L");
    result.replace(QRegularExpression("[ÑŃŇ]"), "N");
    result.replace(QRegularExpression("[ÒÓÔÕÖŌ]"), "O");
    result.replace(QRegularExpression("[Ś]"), "S");
    result.replace(QRegularExpression("[ÙÚÛÜ]"), "U");
    result.replace(QRegularExpression("[Ý]"), "Y");
    result.replace(QRegularExpression("[ŹŻ]"), "Z");

    result.replace(QRegularExpression("[àáâãäåāăą]"), "a");
    result.replace(QRegularExpression("[æ]"), "ae");
    result.replace(QRegularExpression("[çćĉč]"), "c");
    result.replace(QRegularExpression("[èéêëēěę]"), "e");
    result.replace(QRegularExpression("[ìíîï]"), "i");
    result.replace(QRegularExpression("[ł]"), "l");
    result.replace(QRegularExpression("[ñńň]"), "n");
    result.replace(QRegularExpression("[òóôõöō]"), "o");
    result.replace(QRegularExpression("[ś]"), "s");
    result.replace(QRegularExpression("[ùúûü]"), "u");
    result.replace(QRegularExpression("[ýÿ]"), "y");
    result.replace(QRegularExpression("[źż]"), "z");

    result.remove(QRegExp("[^a-zA-Z\\d+-/]"));

    while(result.contains("--")) {
        result.replace("--", "-");
    }

    result = result.toLower();

    return result;
}

QString StringUtils::removeSpecialCharacters(const QString &string) {
    QString result = string;
    return result.remove(QRegExp("[^a-zA-Z\\d+-/]"));
}

QString StringUtils::removeFileName(const QString &filePath) {
    int index = filePath.lastIndexOf("/");
    if(index >= 0) {
        return filePath.left(index);
    }
    return filePath;
}

QString StringUtils::removeFileExtension(const QString &filePath) {
    int index = filePath.lastIndexOf(".");
    if(index >= 0) {
        return filePath.left(index);
    }
    return filePath;
}

QString StringUtils::getFileExtension(const QString &filePath) {
    int index = filePath.lastIndexOf(".");
    if(index >= 0) {
        return filePath.mid(index+1);
    }
    return "";
}

QString StringUtils::replaceFileExtension(const QString &filePath, const QString &newExtension) {
    int index = filePath.lastIndexOf(".");
    if(index >= 0) {
        return filePath.left(index+1) + newExtension;
    }
    return filePath + "." + newExtension;
}
