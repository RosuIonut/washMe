#include <QCoreApplication>

#include "dbconnection.h"
#include "dbDefines.h"

static const int TCP_PORT   = 5600;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    dbConnection *connection = dbConnection::getInstance();

    connection->createConnection();

    return a.exec();
}
