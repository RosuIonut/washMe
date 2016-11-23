#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QSqlDatabase>
#include <QObject>
#include <QString>
#include <QSqlQuery>

#include "dbDefines.h"


class dbConnection: public QObject
{
    Q_OBJECT
private:
    dbConnection();
    dbConnection(dbConnection const& copy);
    dbConnection& operator=(dbConnection const& copy);

    static dbConnection* pInstance;
    QSqlDatabase washMeDatabase;

    bool isDbConnected;
public:
    static dbConnection* getInstance();

    /* Connection methods */
    bool createConnection();

    /* -- Database operation methods - each returns error codes -- */

    /* ---------------------- USERS -------------------------------*/
    uint addUser(QString uName, QString uPass);
    uint addUser(QString uName, QString uPass, QString uEmail);
    /*-------------------------------------------------------------*/
    uint setUserPass(uint uId, QString uPass);
    uint setUserPass(uint uId, QString uOldPass, QString uNewPass);
    uint setUserEmail(uint uId, QString uEmail);
    uint setUserRating(uint uId, QString uRating);
    /*-------------------------------------------------------------*/
    uint getUserName(QString *puName,uint uId);
    uint getUserId(uint *puId,QString uName, QString uPass);
    uint getUserPass(QString *puPass, uint uId);
    uint getUserRating(QString *puRating, uint uId);
    uint getUserEmail(QString *puEmail, uint uId);
    uint getAllUsers(QList<stUsers> *lAllUsers);

    /* ---------------------- EMPLOYEES ---------------------------*/
    uint addEmployee(uint wvId,QString eName);
    uint addEmployee(uint wvId,QString eName,QString eInfo);
    /*-------------------------------------------------------------*/
    uint setEmployeeInfo(uint eId, QString eInfo);
    uint setEmployeeRating(uint eId, QString eRating);
    /*-------------------------------------------------------------*/
    uint getEmployeeId(uint *peId, uint wvId, QString eName);
    uint getEmployeeName(QString *peName, uint eId);
    uint getEmployeeInfo(QString *peInfo, uint eId);
    uint getEmployeeRating(QString *peRating, uint eId);
    uint getEmployeeWashVendor(uint *peWv, uint eId);
    uint getAllEmployees(QList<stEmployees> *lEmployeesForWashVendor);
    uint getEmployeesForWashVendor(uint wvId, QList<stEmployees> *lEmployeesForWashVendor);

    /* ---------------------- WASH VENDORS-------------------------*/
    uint addWashVendor(QString wvName, QString wvPass);
    uint addWashVendor(QString wvName, QString wvPass, QString wvGpsLocation,
               QString wvSchedule, uint wvCapacity, QString wvWashTypes);
    /*-------------------------------------------------------------*/
    uint setWashVendorDetails(uint wvId, QString wvDetails);
    uint setWashVendorPass(uint wvId, QString wvOldPass, QString wvNewPass);
    uint setWashVendorSchedule(uint wvId, QString wvSchedule);
    uint setWashVendorGpsLocation(uint wvId, QString wvGpsLocation);
    uint setWashVendorCapacity(uint wvId, uint wvCapacity);
    uint setWashVendorWashTypes(uint wvId, QString wvWashTypes);
    uint setWashVendorRating(uint wvId, QString wvRating);
    /*-------------------------------------------------------------*/
    uint getWashVendorDetails(QString *pwvDetails, uint wvId);
    uint getWashVendorSchedule(QString *pwvSchedule, uint wvId);
    uint getWashVendorGpsLocation(QString *pwvGpsLocation, uint wvId);
    uint getWashVendorCapacity(uint *pwvCapacity, uint wvId);
    uint getWashVendorWashTypes(QString *pwvWashTypes, uint wvId);
    uint getWashVendorRating(QString *pwvRating, uint wvId);
    uint getAllWashVendors(QList<stWashVendors> *lWashVendors);

    /* ---------------------- RESERVATIONS ------------------------*/
    uint addReservation(uint wvId, uint userId, QString rWashType, QString rWashHour);
    /*-------------------------------------------------------------*/
    uint setReservationEmployee(uint rId, uint eId);
    uint setReservationStatus(uint rId, uint rStatus);
    uint setReservationWashingHour(uint rId, QString rWashingHour);
    uint setReservationWashBlock(uint rId, uint rWashBlock);
    uint setReservationWashType(uint rId, QString rWashType);
    /*-------------------------------------------------------------*/
    uint getReservationWashVendor(uint rId, uint *prwv);
    uint getReservationUser(uint rId, uint *pruId);
    uint getReservationEmployee(uint rId, uint *preId);
    uint getReservationWashType(uint rId, QString *prWashType);
    uint getReservationStatus(uint rId, uint *prStatus);
    uint getReservationWashBlock(uint rId, uint *prWashBlock);
    uint getReservation(uint rId, stReservation *pReservation);
    uint getAllReservations(QList<stReservation> *pAllReservations);
    uint getReservationsForVendor(uint vId, QList<stReservation> *pReservationsForVendor);
    uint getReservationsForUser(uint uId, QList<stReservation> *pReservationsForUser);
    uint getReservationsForEmployee(uint eId, uint wvId, QList<stReservation> *pReservationForEmployee);
    /* ---------------------- PRICES ------------------------*/
    uint addPrice(uint wvId, QString pWashType, uint pValue);
    /*-------------------------------------------------------------*/
    uint setPrice(uint pId, uint pValue);
    /*-------------------------------------------------------------*/
    uint getPrice(uint pId, uint* ppValue);
    uint getPrice(uint wvId, QString pWashType, uint* ppValue);
    uint getPricesForWashVendor(uint vwId, QList<stPrices> *lPricesForVendor);

};

#endif // DBCONNECTION_H
