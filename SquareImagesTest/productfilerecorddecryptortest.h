#ifndef PRODUCTFILERECORDDECRYPTORTEST_H
#define PRODUCTFILERECORDDECRYPTORTEST_H

#include <QObject>

class ProductFileRecordDecryptorTest : public QObject
{
    Q_OBJECT

private slots:
    void decryptFileRecord_data();
    void decryptFileRecord();
};

#endif // PRODUCTFILERECORDDECRYPTORTEST_H
