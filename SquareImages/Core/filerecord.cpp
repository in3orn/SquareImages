#include "filerecord.h"

#include <QObject>

FileRecord::FileRecord() :
    inputFilePath(""),
    inputFileName(""),
    outputFilePath(""),
    outputFileName(""),

    _error(""),

    _status(Waiting)
{

}

void FileRecord::setError(const QString &error) {
    _error = error;

    if(!error.isEmpty()) _status = Error;
}

QString FileRecord::getError() const {
    return _error;
}

QString FileRecord::getStatusString() const {
    switch(_status) {
    case Waiting:
        return QObject::tr("Czeka na przetworzenie");
    case Success:
        return QObject::tr("Przetworzony poprawnie");
    case Omitted:
        return QObject::tr("Zdjęcie już istnieje");
    case Error:
        return QObject::tr("Błąd przetwarzania");
    default:
        return "";
    }
}

void FileRecord::finish() {
    if(_error.isEmpty())
        _status = Success;
}

void FileRecord::omit() {
    _status = Omitted;
}
