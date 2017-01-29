#ifndef BRANDFILERECORDDECRYPTORTEST_H
#define BRANDFILERECORDDECRYPTORTEST_H

#include <QObject>

class BrandFileRecordDecryptorTest : public QObject
{
    Q_OBJECT

private slots:
    void decryptFileRecord_data();
    void decryptFileRecord();
};

#endif // BRANDFILERECORDDECRYPTORTEST_H
