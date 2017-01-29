#ifndef SIMPLEFILERECORDDECRYPTORTEST_H
#define SIMPLEFILERECORDDECRYPTORTEST_H

#include <QObject>

class SimpleFileRecordDecryptorTest : public QObject
{
    Q_OBJECT

private slots:
    void decryptFileRecord_data();
    void decryptFileRecord();
};

#endif // SIMPLEFILERECORDDECRYPTORTEST_H
