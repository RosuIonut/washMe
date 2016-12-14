#include "dbtest.h"

dbTest::dbTest(QObject *parent) :
    QObject(parent)
{
    database = dbConnection::getInstance();
}

void dbTest::testAddUser()
{
    uint ecAddUser = 0;
    uint ecAddUser1 = 0;
    ecAddUser = database->addUser("TestUserName_1","TestUserPassword_1","TestUserEmail_1");
    ecAddUser1 = database->addUser("TestUserName_2","TestUserPassword_2");

    if (ecAddUser != 0)
        qDebug()<<"dbTest::testAddUser() failed on addUser long method. Error code: "+QString::number(ecAddUser)+"\n";
    if (ecAddUser1 != 0)
        qDebug()<<"dbTest::testAddUser() failed on addUser short method. Error code: "+QString::number(ecAddUser1)+"\n";
}

void dbTest::testSetUser()
{
//    uint ecEmail = 0;
//    uint ecPassword = 0;
//    uint ecPassword1 = 0;
//    uint ecRating = 0;

//    ecEmail = database->setUserEmail(1,"Email for uid 1");
//    ecPassword = database->setUserPass(1,"")

}

void dbTest::testGetUser()
{

}

void dbTest::testAddEmployee()
{

}

void dbTest::testSetEmployee()
{

}

void dbTest::testGetEmployee()
{

}

void dbTest::testAddWashVendor()
{

}

void dbTest::testGetWashVendors()
{

}

void dbTest::testSetWashVendors()
{

}

void dbTest::testAddReservation()
{

}

void dbTest::testGetReservation()
{

}

void dbTest::testSetReservation()
{

}

void dbTest::testDatabase()
{
    testAddUser();
    testSetUser();
    testGetUser();
    testAddEmployee();
    testGetEmployee();
    testSetEmployee();
    testAddWashVendor();
    testSetWashVendors();
    testGetWashVendors();
    testAddReservation();
    testGetReservation();
    testSetReservation();
}
