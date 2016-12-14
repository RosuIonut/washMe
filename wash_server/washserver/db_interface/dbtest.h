#ifndef DBTEST_H
#define DBTEST_H

#include <QObject>
#include <QDebug>
#include "dbconnection.h"


class dbTest : public QObject
{
    Q_OBJECT
public:
    explicit dbTest(QObject *parent = 0);
    void testDatabase();
private:
    /* Test all methods that adds an user */
    void testAddUser();
    /* Test all setters methods for user */
    void testSetUser();
    /* Test all getters methods for user */
    void testGetUser();
    /* Test all methods that adds an employee */
    void testAddEmployee();
    /* Test all setters methods for employees */
    void testSetEmployee();
    /* Test all getters methods for employees */
    void testGetEmployee();
    /* Test all methods that adds an wash vendor */
    void testAddWashVendor();
    /* Test all getters methods for wash vendor */
    void testGetWashVendors();
    /* Test all setters methods for wash vendor */
    void testSetWashVendors();
    /* Test all methods that adds an reservation */
    void testAddReservation();
    /* Test all getters methods for reservations */
    void testGetReservation();
    /* Test all setters methods for reservations */
    void testSetReservation();
    /* Instance to database connection class */
    dbConnection* database;
signals:

public slots:

};

#endif // DBTEST_H
