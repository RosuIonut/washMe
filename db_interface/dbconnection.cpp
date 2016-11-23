#include "dbconnection.h"
#include "dbDefines.h"
#include <QDebug>
#include "QSqlError"

dbConnection* dbConnection::pInstance = NULL;

dbConnection *dbConnection::getInstance()
{
    if (!pInstance)
        pInstance = new dbConnection;
    return pInstance;
}

dbConnection::dbConnection()
{
    isDbConnected = 0;
}

bool dbConnection::createConnection()
{
    washMeDatabase = QSqlDatabase::addDatabase("QMYSQL3");
    washMeDatabase.setHostName("localhost");
    washMeDatabase.setPort(3306);
    washMeDatabase.setUserName("root");
    washMeDatabase.setPassword("!QAZ2wsx");
    isDbConnected = washMeDatabase.open();

    if (isDbConnected)
        qDebug("Database connection successful");
    else
        qDebug("Databse connection unsuccessful");

    return isDbConnected;
}

uint dbConnection::addUser(QString uName, QString uPass)
{
    bool result;
    QSqlQuery query;
    QString command = "INSERT INTO `wash_me`.`users` (`iduser`, `name`, `email`, `password`) VALUES ('', '"+
                      uName+"', '', '"+ uPass +"');";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::addUser(QString uName, QString uPass, QString uEmail)
{
    bool result;
    QSqlQuery query;
    QString command = "INSERT INTO `wash_me`.`users` (`iduser`, `name`, `email`, `password`) VALUES ('', '"
                      + uName+"', '"+ uEmail +"', '"+ uPass +"');";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setUserPass(uint uId, QString uPass)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`users` SET `password`='"
                      + uPass +"' WHERE `iduser`="+QString::number(uId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setUserPass(uint uId, QString uOldPass, QString uNewPass)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT password FROM wash_me.users WHERE iduser = "
                      +QString::number(uId)+";";
    result = query.exec(command);

    if (result == true && query.first())
        if (query.value("password") == uOldPass)
        {
            command = "UPDATE `wash_me`.`users` SET `password`='"+ uNewPass
                      +"' WHERE `iduser`="+QString::number(uId)+";";
            result = query.exec(command);

            if (result == true)
                return 0;
            else
                return 1;
        }
        else
        {
            return 2;
        }

    else
        return 1;
}

uint dbConnection::setUserEmail(uint uId, QString uEmail)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`users` SET `email`='"
                       + uEmail +"' WHERE `iduser`="+QString::number(uId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setUserRating(uint uId, QString uRating)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`users` SET `rating`='"
                      + uRating +"' WHERE `iduser`="+QString::number(uId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::getUserName(QString *puName, uint uId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT name FROM wash_me.users WHERE iduser = "
                      +QString::number(uId)+";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *puName = query.value("name").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getUserId(uint *puId, QString uName, QString uPass)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT iduser FROM wash_me.users WHERE name ='"
                      +uName+"' AND password ='"+uPass+"';";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *puId = query.value("iduser").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getUserPass(QString *puPass, uint uId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT password FROM wash_me.users WHERE iduser = "
                       +QString::number(uId)+";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *puPass = query.value("password").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getUserRating(QString *puRating, uint uId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT rating FROM wash_me.users WHERE iduser = "
                      +QString::number(uId)+";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *puRating = query.value("rating").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getUserEmail(QString *puEmail, uint uId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT email FROM wash_me.users WHERE iduser = "
                      +QString::number(uId)+";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *puEmail = query.value("email").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getAllUsers(QList<stUsers> *lAllUsers)
{   
    bool result;
    QSqlQuery query;
    stUsers auxUser;

    QString command = "SELECT * FROM wash_me.users;";

    result = query.exec(command);

    if (result == true && query.first())
    {
        for (int i = 0; i < query.size(); i++)
        {
            auxUser.id = query.value("iduser").toUInt();
            auxUser.name = query.value("name").toString();
            auxUser.email = query.value("email").toString();
            auxUser.password = query.value("password").toString();
            auxUser.rating = query.value("rating").toString();

            lAllUsers->append(auxUser);
            query.next();
        }
        return 0;
    }
    else
        return 1;
}

uint dbConnection::addEmployee(uint wvId, QString eName)
{
    bool result;
    QSqlQuery query;

    QString command = "INSERT INTO `wash_me`.`employee` (`idwash_vendor`, `name`, `info`, `rating`) VALUES ("
                       + QString::number(wvId) +", '"+ eName +"', '', '');";

    result = query.exec(command);

    if (result == true)
    {
        return 0;
    }
    else
        return 1;
}

uint dbConnection::addEmployee(uint wvId, QString eName, QString eInfo)
{
    bool result;
    QSqlQuery query;

    QString command = "INSERT INTO `wash_me`.`employee` (`idwash_vendor`, `name`, `info`, `rating`) VALUES ("
                      + QString::number(wvId) +", '"+ eName +"', '"+ eInfo +"', '');";

    result = query.exec(command);

    if (result == true)
    {
        return 0;
    }
    else
        return 1;
}

uint dbConnection::setEmployeeInfo(uint eId, QString eInfo)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`employee` SET `info`='"+ eInfo
                      +"' WHERE `idemployee`="+QString::number(eId)+";";

    result = query.exec(command);

    if (result == true)
    {
        return 0;
    }
    else
        return 1;
}

uint dbConnection::setEmployeeRating(uint eId, QString eRating)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`employee` SET `rating`='"+ eRating
                      +"' WHERE `idemployee`="+QString::number(eId)+";";

    result = query.exec(command);

    if (result == true)
    {
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getEmployeeId(uint *peId, uint wvId, QString eName)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT idemployee FROM wash_me.employee WHERE idwash_vendor = "
                      + QString::number(wvId) +" AND name = '"+ eName +"';";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *peId = query.value("idemployee").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getEmployeeName(QString *peName, uint eId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT name FROM wash_me.employee WHERE idemployee = "
                      + QString::number(eId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *peName = query.value("name").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getEmployeeInfo(QString *peInfo, uint eId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT info FROM wash_me.employee WHERE idemployee = "
                      + QString::number(eId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *peInfo = query.value("info").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getEmployeeRating(QString *peRating, uint eId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT rating FROM wash_me.employee WHERE idemployee = "
                      + QString::number(eId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *peRating = query.value("rating").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getEmployeeWashVendor(uint *peWv, uint eId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT idwash_vendor FROM wash_me.employee WHERE idemployee = "
                      + QString::number(eId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *peWv = query.value("idwash_vendor").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getAllEmployees(QList<stEmployees>* lEmployeesForWashVendor)
{
    bool result;
    QSqlQuery query;
    stEmployees auxEmployee;

    QString command = "SELECT * FROM wash_me.employee;";

    result = query.exec(command);

    if (result == true && query.first())
    {
        for (int i = 0; i < query.size(); i++)
        {
            auxEmployee.id = query.value("idemployee").toUInt();
            auxEmployee.id_washVendor = query.value("idwash_vendor").toUInt();
            auxEmployee.name = query.value("name").toString();
            auxEmployee.info = query.value("info").toString();
            auxEmployee.rating = query.value("rating").toString();

            lEmployeesForWashVendor->append(auxEmployee);
            query.next();
        }
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getEmployeesForWashVendor(uint wvId, QList<stEmployees>* lEmployeesForWashVendor)
{
    bool result;
    QSqlQuery query;
    stEmployees auxEmployee;

    QString command = "SELECT * FROM wash_me.employee WHERE idwash_vendor = "
                      + QString::number(wvId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        for (int i = 0; i < query.size(); i++)
        {
            auxEmployee.id = query.value("idemployee").toUInt();
            auxEmployee.id_washVendor = query.value("idwash_vendor").toUInt();
            auxEmployee.name = query.value("name").toString();
            auxEmployee.info = query.value("info").toString();
            auxEmployee.rating = query.value("rating").toString();

            lEmployeesForWashVendor->append(auxEmployee);
            query.next();
        }
        return 0;
    }
    else
        return 1;
}

uint dbConnection::addWashVendor(QString wvName, QString wvPass)
{
    bool result;
    QSqlQuery query;

    QString command = "INSERT INTO `wash_me`.`wash_vendors` (`name`, `password`, `details`, `schedule`, `gpslocation`, `capacity`, `washing_types`, `rating`)"
                      "VALUES ('"+ wvName +"', '"+ wvPass +"', '', '', '', '', '', '');";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::addWashVendor(QString wvName, QString wvPass, QString wvGpsLocation, QString wvSchedule, uint wvCapacity, QString wvWashTypes)
{
    bool result;
    QSqlQuery query;

    QString command = "INSERT INTO `wash_me`.`wash_vendors` (`name`, `password`, `details`, `schedule`, `gpslocation`, `capacity`, `washing_types`, `rating`)"
                      " VALUES ('"+ wvName +"', '"+ wvPass +"', '', '"+wvSchedule+"', '"+wvGpsLocation+"', "+QString::number(wvCapacity)+", '"+wvWashTypes+"', '');";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setWashVendorDetails(uint wvId, QString wvDetails)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`wash_vendors` SET `details`='"+ wvDetails
                      +"' WHERE `idwash_vendors`="+QString::number(wvId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setWashVendorPass(uint wvId, QString wvOldPass, QString wvNewPass)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT password FROM wash_me.wash_vendors WHERE idwash_vendors = "
                      +QString::number(wvId)+";";
    result = query.exec(command);

    if (result == true && query.first())
    {
        if (query.value("password").toString() == wvOldPass)
        {
            command = "UPDATE `wash_me`.`wash_vendors` SET `password`='"+ wvNewPass
                      +"' WHERE `idwash_vendors`="+QString::number(wvId)+";";
            result = query.exec(command);

            if (result == true)
                return 0;
            else
                return 1;
        }
        else
        {
            return 2;
        }
    }
    else
        return 1;
}

uint dbConnection::setWashVendorSchedule(uint wvId, QString wvSchedule)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`wash_vendors` SET `schedule`='"+ wvSchedule
                      +"' WHERE `idwash_vendors`="+QString::number(wvId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setWashVendorGpsLocation(uint wvId, QString wvGpsLocation)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`wash_vendors` SET `gpslocation`='"+ wvGpsLocation
                      +"' WHERE `idwash_vendors`="+QString::number(wvId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setWashVendorCapacity(uint wvId, uint wvCapacity)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`wash_vendors` SET `capacity`="+ QString::number(wvCapacity)
                      +" WHERE `idwash_vendors`="+ QString::number(wvId) +";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setWashVendorWashTypes(uint wvId, QString wvWashTypes)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`wash_vendors` SET `washing_types`='"
                      + wvWashTypes +"' WHERE `idwash_vendors`="+QString::number(wvId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setWashVendorRating(uint wvId, QString wvRating)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`wash_vendors` SET `rating`="+ wvRating
                      +" WHERE `idwash_vendors`="+QString::number(wvId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::getWashVendorDetails(QString *pwvDetails, uint wvId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT details FROM wash_me.wash_vendors WHERE idwash_vendors = "
                      + QString::number(wvId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *pwvDetails = query.value("details").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getWashVendorSchedule(QString *pwvSchedule, uint wvId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT schedule FROM wash_me.wash_vendors WHERE idwash_vendors = "
                      + QString::number(wvId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *pwvSchedule = query.value("schedule").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getWashVendorGpsLocation(QString *pwvGpsLocation, uint wvId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT gpslocation FROM wash_me.wash_vendors WHERE idwash_vendors = "
                      + QString::number(wvId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *pwvGpsLocation = query.value("gpslocation").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getWashVendorCapacity(uint *pwvCapacity, uint wvId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT capacity FROM wash_me.wash_vendors WHERE idwash_vendors = "
                      + QString::number(wvId) +";";

    result = query.exec(command);


    if (result == true && query.first())
    {
        *pwvCapacity = query.value("capacity").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getWashVendorWashTypes(QString *pwvWashTypes, uint wvId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT washing_types FROM wash_me.wash_vendors WHERE idwash_vendors = "
                      + QString::number(wvId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *pwvWashTypes = query.value("washing_types").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getWashVendorRating(QString *pwvRating, uint wvId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT rating FROM wash_me.wash_vendors WHERE idwash_vendors = "
                      + QString::number(wvId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *pwvRating = query.value("rating").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getAllWashVendors(QList<stWashVendors>* lWashVendors)
{
    bool result;
    QSqlQuery query;
    stWashVendors auxWashVendor;

    QString command = "SELECT * FROM wash_me.wash_vendors;";

    result = query.exec(command);

    if (result == true && query.first())
    {
        for (int i = 0; i < query.size(); i++)
        {
            auxWashVendor.id = query.value("idwash_vendors").toInt();
            auxWashVendor.name = query.value("name").toString();
            auxWashVendor.password = query.value("password").toString();
            auxWashVendor.details = query.value("details").toString();
            auxWashVendor.schedule = query.value("schedule").toString();
            auxWashVendor.gpsLocation = query.value("gpslocation").toString();
            auxWashVendor.capacity = query.value("capacity").toString();
            auxWashVendor.washingTypes = query.value("washing_types").toString();
            auxWashVendor.rating = query.value("rating").toString();

            lWashVendors->append(auxWashVendor);
            query.next();
        }
        return 0;
    }
    else
        return 1;
}

uint dbConnection::addReservation(uint wvId, uint userId, QString rWashType, QString rWashHour)
{
    bool result;
    QSqlQuery query;

    QString command = "INSERT INTO `wash_me`.`reservs` (`idwash_vendor`, `iduser`, `idemployee`, `washing_type`, `washing_hour`, `status`, `wash_block`)"
                      " VALUES ("+ QString::number(wvId) +","+ QString::number(userId) +",'','"+ rWashType
                      + "', '"+rWashHour+"','','');";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setReservationEmployee(uint rId, uint eId)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`reservs` SET `idemployee`=" + QString::number(eId)
                      +" WHERE `idreservs`="+QString::number(rId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setReservationStatus(uint rId, uint rStatus)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`reservs` SET `status`='" + QString::number(rStatus)
                      +"' WHERE `idreservs`="+QString::number(rId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setReservationWashingHour(uint rId, QString rWashingHour)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`reservs` SET `washing_hour`='" + rWashingHour
                      +"' WHERE `idreservs`="+QString::number(rId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setReservationWashBlock(uint rId, uint rWashBlock)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`reservs` SET `wash_block`='" + QString::number(rWashBlock)
                      +"' WHERE `idreservs`="+QString::number(rId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setReservationWashType(uint rId, QString rWashType)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`reservs` SET `washing_type`='" + rWashType
                      +"' WHERE `idreservs`="+QString::number(rId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::getReservationWashVendor(uint rId, uint *prwv)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT idwash_vendor FROM wash_me.reservs WHERE idreservs = "
                      + QString::number(rId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *prwv = query.value("idwash_vendor").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getReservationUser(uint rId, uint *pruId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT iduser FROM wash_me.reservs WHERE idreservs = "
                      + QString::number(rId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *pruId = query.value("iduser").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getReservationEmployee(uint rId, uint *preId)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT idemployee FROM wash_me.reservs WHERE idreservs = "
                      + QString::number(rId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *preId = query.value("idemployee").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getReservationWashType(uint rId, QString *prWashType)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT washing_type FROM wash_me.reservs WHERE idreservs = "
                      + QString::number(rId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *prWashType = query.value("washing_type").toString();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getReservationStatus(uint rId, uint *prStatus)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT status FROM wash_me.reservs WHERE idreservs = "
                      + QString::number(rId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *prStatus = query.value("status").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getReservationWashBlock(uint rId, uint *prWashBlock)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT wash_block FROM wash_me.reservs WHERE idreservs = "
                      + QString::number(rId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *prWashBlock = query.value("wash_block").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getReservation(uint rId, stReservation* pReservation)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT * FROM wash_me.reservs WHERE idreservs = "
                      + QString::number(rId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        pReservation->id = query.value("idreservs").toUInt();
        pReservation->id_washVendor = query.value("idwash_vendor").toUInt();
        pReservation->id_user = query.value("iduser").toUInt();
        pReservation->id_employee = query.value("idemployee").toUInt();
        pReservation->washing_type = query.value("washing_type").toString();
        pReservation->washing_hour = query.value("washing_hour").toString();
        pReservation->status = query.value("status").toUInt();
        pReservation->washing_block = query.value("wash_block").toUInt();

        return 0;
    }
    else
        return 1;
}

uint dbConnection::getAllReservations(QList<stReservation> *pAllReservations)
{
    bool result;
    QSqlQuery query;
    stReservation auxReservation;

    QString command = "SELECT * FROM wash_me.reservs";

    result = query.exec(command);

    if (result == true && query.first())
    {
        for (int i = 0; i< query.size(); i++)
        {
            auxReservation.id = query.value("idreservs").toUInt();
            auxReservation.id_washVendor = query.value("idwash_vendor").toUInt();
            auxReservation.id_user = query.value("iduser").toUInt();
            auxReservation.id_employee = query.value("idemployee").toUInt();
            auxReservation.washing_type = query.value("washing_type").toString();
            auxReservation.washing_hour = query.value("washing_hour").toString();
            auxReservation.status = query.value("status").toUInt();
            auxReservation.washing_block = query.value("wash_block").toUInt();

            pAllReservations->append(auxReservation);
            query.next();
        }
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getReservationsForVendor(uint vId, QList<stReservation> *pReservationsForVendor)
{
    bool result;
    QSqlQuery query;
    stReservation auxReservation;

    QString command = "SELECT * FROM wash_me.reservs WHERE idwash_vendor = "
                      + QString::number(vId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        for (int i = 0; i< query.size(); i++)
        {
            auxReservation.id = query.value("idreservs").toUInt();
            auxReservation.id_washVendor = query.value("idwash_vendor").toUInt();
            auxReservation.id_user = query.value("iduser").toUInt();
            auxReservation.id_employee = query.value("idemployee").toUInt();
            auxReservation.washing_type = query.value("washing_type").toString();
            auxReservation.washing_hour = query.value("washing_hour").toString();
            auxReservation.status = query.value("status").toUInt();
            auxReservation.washing_block = query.value("wash_block").toUInt();

            pReservationsForVendor->append(auxReservation);
            query.next();
        }
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getReservationsForUser(uint uId, QList<stReservation> *pReservationsForUser)
{
    bool result;
    QSqlQuery query;
    stReservation auxReservation;

    QString command = "SELECT * FROM wash_me.reservs WHERE iduser = "
                      + QString::number(uId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        for (int i = 0; i< query.size(); i++)
        {
            auxReservation.id = query.value("idreservs").toUInt();
            auxReservation.id_washVendor = query.value("idwash_vendor").toUInt();
            auxReservation.id_user = query.value("iduser").toUInt();
            auxReservation.id_employee = query.value("idemployee").toUInt();
            auxReservation.washing_type = query.value("washing_type").toString();
            auxReservation.washing_hour = query.value("washing_hour").toString();
            auxReservation.status = query.value("status").toUInt();
            auxReservation.washing_block = query.value("wash_block").toUInt();

            pReservationsForUser->append(auxReservation);
            query.next();
        }
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getReservationsForEmployee(uint eId, uint wvId, QList<stReservation> *pReservationForEmployee)
{
    bool result;
    QSqlQuery query;
    stReservation auxReservation;

    QString command = "SELECT * FROM wash_me.reservs WHERE idemployee = "+ QString::number(eId)
                      +" AND idwash_vendor ="+ QString::number(wvId) + ";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        for (int i = 0; i < query.size(); i++)
        {
            auxReservation.id = query.value("idreservs").toUInt();
            auxReservation.id_washVendor = query.value("idwash_vendor").toUInt();
            auxReservation.id_user = query.value("iduser").toUInt();
            auxReservation.id_employee = query.value("idemployee").toUInt();
            auxReservation.washing_type = query.value("washing_type").toString();
            auxReservation.washing_hour = query.value("washing_hour").toString();
            auxReservation.status = query.value("status").toUInt();
            auxReservation.washing_block = query.value("wash_block").toUInt();

            pReservationForEmployee->append(auxReservation);
            query.next();
        }
        return 0;
    }
    else
        return 1;
}

uint dbConnection::addPrice(uint wvId, QString pWashType, uint pValue)
{
    bool result;
    QSqlQuery query;

    QString command = "INSERT INTO `wash_me`.`prices` (`id_washvendor`, `wash_type`, `price_value`)"
                      " VALUES ("+ QString::number(wvId) +",'"+ pWashType +"',"+ QString::number(pValue)+");";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::setPrice(uint pId, uint pValue)
{
    bool result;
    QSqlQuery query;

    QString command = "UPDATE `wash_me`.`prices` SET `price_value`='" + QString::number(pValue)
                      +"' WHERE `id_price`="+QString::number(pId)+";";

    result = query.exec(command);

    if (result == true)
        return 0;
    else
        return 1;
}

uint dbConnection::getPrice(uint pId, uint *ppValue)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT price_value FROM wash_me.prices WHERE id_price = "
                      + QString::number(pId) +";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *ppValue = query.value("price_value").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getPrice(uint wvId, QString pWashType, uint *ppValue)
{
    bool result;
    QSqlQuery query;

    QString command = "SELECT price_value FROM wash_me.prices WHERE id_washvendor = "+ QString::number(wvId)
                      +" AND wash_type = '"+ pWashType +"';";

    result = query.exec(command);

    if (result == true && query.first())
    {
        *ppValue = query.value("price_value").toUInt();
        return 0;
    }
    else
        return 1;
}

uint dbConnection::getPricesForWashVendor(uint vwId, QList<stPrices> * lPricesForVendor)
{
    bool result;
    QSqlQuery query;
    stPrices auxPrice;

    QString command = "SELECT * FROM wash_me.prices WHERE id_washvendor = "+ QString::number(vwId)+";";

    result = query.exec(command);

    if (result == true && query.first())
    {
        for (int i = 0; i < query.size(); i++)
        {
            auxPrice.id_washVendor = query.value("id_washvendor").toUInt();
            auxPrice.id_price = query.value("id_price").toUInt();
            auxPrice.wash_type = query.value("wash_type").toString();
            auxPrice.value = query.value("price_value").toUInt();

            lPricesForVendor->append(auxPrice);
            query.next();
        }
        return 0;
    }
    else
        return 1;
}
