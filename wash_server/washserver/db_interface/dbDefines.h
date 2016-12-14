#ifndef DBDEFINES_H
#define DBDEFINES_H

enum dbErrorCodes
{
    noError = 0,
    invalidError = -1
};

enum reservationStatus
{
    pending = 0,
    confirmed = 1,
    cancelled = 2,
    done = 3,
    invalidStatus = 4
};

struct stWashVendors
{
    uint id;
    QString name;
    QString password;
    QString details;
    QString schedule;
    QString gpsLocation;
    QString capacity;
    QString washingTypes;
    QString rating;
};

struct stEmployees
{
    uint id;
    uint id_washVendor;
    QString name;
    QString info;
    QString rating;
};

struct stUsers
{
    uint id;
    QString name;
    QString email;
    QString password;
    float rating;
};

struct stReservation
{
    uint id;
    uint id_washVendor;
    uint id_user;
    uint id_employee;
    QString washing_type;
    QString washing_hour;
    uint status;
    uint washing_block;
};

struct stPrices
{
    uint id_washVendor;
    uint id_price;
    QString wash_type;
    uint value;
};



#endif // DBDEFINES_H
