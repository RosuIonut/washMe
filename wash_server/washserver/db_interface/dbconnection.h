#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QThreadStorage>

#include "dbDefines.h"


class dbConnection
{
    dbConnection();
    dbConnection(dbConnection const& copy);
    dbConnection& operator=(dbConnection const& copy);

    static dbConnection* pInstance;

    // http://doc.qt.io/qt-5/threads-modules.html
    // A connection can only be used from within the thread that created it.
    QThreadStorage<QSqlDatabase> dbStorage;

public:
    enum ReturnCode
    {
        OK = 0,
        NOT_FOUND,
        FAIL,
        PASSWORD_DONT_MATCH
    };

    static dbConnection* getInstance();

    /* Connection methods */
    QSqlDatabase& getConnection();

    /* -- Database operation methods - each returns error codes -- */

    /* ---------------------- USERS -------------------------------*/
    ReturnCode addUser(QString uName, QString uPass);
    ReturnCode addUser(QString uName, QString uPass, QString uEmail);
    /*-------------------------------------------------------------*/
    ReturnCode setUserPass(uint uId, QString uPass);
    ReturnCode setUserPass(uint uId, QString uOldPass, QString uNewPass);
    ReturnCode setUserEmail(uint uId, QString uEmail);
    ReturnCode setUserRating(uint uId, QString uRating);
    /*-------------------------------------------------------------*/
    ReturnCode getUserName(QString *puName,uint uId);
    ReturnCode getUserId(uint *puId,QString uName, QString uPass);
    ReturnCode getUserPass(QString *puPass, uint uId);
    ReturnCode getUserRating(QString *puRating, uint uId);
    ReturnCode getUserEmail(QString *puEmail, uint uId);
    ReturnCode getUserDetails(uint uId, stUsers& user);
    ReturnCode getAllUsers(QList<stUsers> *lAllUsers);

    /* ---------------------- EMPLOYEES ---------------------------*/
    ReturnCode addEmployee(uint wvId,QString eName);
    ReturnCode addEmployee(uint wvId,QString eName,QString eInfo);
    /*-------------------------------------------------------------*/
    ReturnCode setEmployeeInfo(uint eId, QString eInfo);
    ReturnCode setEmployeeRating(uint eId, QString eRating);
    /*-------------------------------------------------------------*/
    ReturnCode getEmployeeId(uint *peId, uint wvId, QString eName);
    ReturnCode getEmployeeName(QString *peName, uint eId);
    ReturnCode getEmployeeInfo(QString *peInfo, uint eId);
    ReturnCode getEmployeeRating(QString *peRating, uint eId);
    ReturnCode getEmployeeWashVendor(uint *peWv, uint eId);
    ReturnCode getAllEmployees(QList<stEmployees> *lEmployeesForWashVendor);
    ReturnCode getEmployeesForWashVendor(uint wvId, QList<stEmployees> *lEmployeesForWashVendor);

    /* ---------------------- WASH VENDORS-------------------------*/
    ReturnCode addWashVendor(QString wvName, QString wvPass);
    ReturnCode addWashVendor(QString wvName, QString wvPass, QString wvGpsLocation,
               QString wvSchedule, uint wvCapacity, QString wvWashTypes);
    /*-------------------------------------------------------------*/
    ReturnCode setWashVendorDetails(uint wvId, QString wvDetails);
    ReturnCode setWashVendorPass(uint wvId, QString wvOldPass, QString wvNewPass);
    ReturnCode setWashVendorSchedule(uint wvId, QString wvSchedule);
    ReturnCode setWashVendorGpsLocation(uint wvId, QString wvGpsLocation);
    ReturnCode setWashVendorCapacity(uint wvId, uint wvCapacity);
    ReturnCode setWashVendorWashTypes(uint wvId, QString wvWashTypes);
    ReturnCode setWashVendorRating(uint wvId, QString wvRating);
    /*-------------------------------------------------------------*/
    ReturnCode getWashVendorDetails(QString *pwvDetails, uint wvId);
    ReturnCode getWashVendorSchedule(QString *pwvSchedule, uint wvId);
    ReturnCode getWashVendorGpsLocation(QString *pwvGpsLocation, uint wvId);
    ReturnCode getWashVendorCapacity(uint *pwvCapacity, uint wvId);
    ReturnCode getWashVendorWashTypes(QString *pwvWashTypes, uint wvId);
    ReturnCode getWashVendorRating(QString *pwvRating, uint wvId);
    ReturnCode getAllWashVendors(QList<stWashVendors> *lWashVendors);

    /* ---------------------- RESERVATIONS ------------------------*/
    ReturnCode addReservation(uint wvId, uint userId, QString rWashType, QString rWashHour);
    /*-------------------------------------------------------------*/
    ReturnCode setReservationEmployee(uint rId, uint eId);
    ReturnCode setReservationStatus(uint rId, uint rStatus);
    ReturnCode setReservationWashingHour(uint rId, QString rWashingHour);
    ReturnCode setReservationWashBlock(uint rId, uint rWashBlock);
    ReturnCode setReservationWashType(uint rId, QString rWashType);
    /*-------------------------------------------------------------*/
    ReturnCode getReservationWashVendor(uint rId, uint *prwv);
    ReturnCode getReservationUser(uint rId, uint *pruId);
    ReturnCode getReservationEmployee(uint rId, uint *preId);
    ReturnCode getReservationWashType(uint rId, QString *prWashType);
    ReturnCode getReservationStatus(uint rId, uint *prStatus);
    ReturnCode getReservationWashBlock(uint rId, uint *prWashBlock);
    ReturnCode getReservation(uint rId, stReservation *pReservation);
    ReturnCode getAllReservations(QList<stReservation> *pAllReservations);
    ReturnCode getReservationsForVendor(uint vId, QList<stReservation> *pReservationsForVendor);
    ReturnCode getReservationsForUser(uint uId, QList<stReservation> *pReservationsForUser);
    ReturnCode getReservationsForEmployee(uint eId, uint wvId, QList<stReservation> *pReservationForEmployee);
    /* ---------------------- PRICES ------------------------*/
    ReturnCode addPrice(uint wvId, QString pWashType, uint pValue);
    /*-------------------------------------------------------------*/
    ReturnCode setPrice(uint pId, uint pValue);
    /*-------------------------------------------------------------*/
    ReturnCode getPrice(uint pId, uint* ppValue);
    ReturnCode getPrice(uint wvId, QString pWashType, uint* ppValue);
    ReturnCode getPricesForWashVendor(uint vwId, QList<stPrices> *lPricesForVendor);

};

#endif // DBCONNECTION_H
