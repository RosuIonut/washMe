#include "WashApi.h"
#include "WashServer.h"
#include "Logger.h"
#include "AuthenticationManager.h"
#include "dbconnection.h"

#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#define WASHAPI_AUTHENTICATE \
    uint USERID = 0; \
    if(!(USERID = authManager->IsAuthenticated(request.headers()))) \
    { \
        response.send(Net::Http::Code::Forbidden); \
        WASHAPI_LOG_REQUEST_OUT << "AUTHENTICATION FAILED"; \
        return; \
    }


WashApi::WashApi() :
    db(dbConnection::getInstance()),
    authManager(new AuthenticationManager)
{

}

void WashApi::Login(const Net::Rest::Request &request, Net::Http::ResponseWriter response)
{
    WASHAPI_LOG_REQUEST_IN << "(BODY: " << request.body().c_str() << ")";

    QJsonParseError jsonError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(QString(request.body().c_str()).toUtf8(), &jsonError);

    if(jsonError.error != QJsonParseError::NoError)
    {
        response.send(Net::Http::Code::Bad_Request);
        WASHAPI_LOG_REQUEST_OUT << "REQUEST PARSING ERROR: " << jsonError.errorString();
        return;
    }

    QJsonObject jsonObject = jsonResponse.object();
    if(!jsonObject.contains("username") || !jsonObject.contains("username"))
    {
        response.send(Net::Http::Code::Bad_Request);
        WASHAPI_LOG_REQUEST_OUT << "INVALID REQUEST";
        return;
    }

    QString username = jsonObject["username"].toString();
    QString password = jsonObject["password"].toString();
    uint userId;

    if(db->getUserId(&userId, username, password) != dbConnection::OK)
    {
        response.send(Net::Http::Code::Not_Found);
        WASHAPI_LOG_REQUEST_OUT << "DB_ERROR - Authentication failed";
        return;
    }

    QString token = authManager->AuthenticateUser(userId, username);
    response.headers().add<WashServer::AccessControlHeader>("*");
    response.send(Net::Http::Code::Ok, token.toStdString(), MIME(Application, Plain));
    WASHAPI_LOG_REQUEST_OUT << "OK (username:" << username << ", token:" << token << ")";
}

void WashApi::Signup(const Net::Rest::Request &request, Net::Http::ResponseWriter response)
{
    WASHAPI_LOG_REQUEST_IN << "(BODY: " << request.body().c_str() << ")";

    QJsonParseError jsonError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(QString(request.body().c_str()).toUtf8(), &jsonError);

    if(jsonError.error != QJsonParseError::NoError)
    {
        response.send(Net::Http::Code::Bad_Request);
        WASHAPI_LOG_REQUEST_OUT << "REQUEST PARSING ERROR: " << jsonError.errorString();
        return;
    }

    QJsonObject jsonObject = jsonResponse.object();
    if(!jsonObject.contains("username") || !jsonObject.contains("password") || !jsonObject.contains("email"))
    {
        response.send(Net::Http::Code::Bad_Request);
        WASHAPI_LOG_REQUEST_OUT << "INVALID REQUEST";
        return;
    }

    QString username = jsonObject["username"].toString();
    QString password = jsonObject["password"].toString();
    QString email = jsonObject["email"].toString();

    if(db->addUser(username, password, email) != dbConnection::OK)
    {
        response.send(Net::Http::Code::Bad_Request);
        WASHAPI_LOG_REQUEST_OUT << "DB_ERROR - Add User failed";
        return;
    }

    response.send(Net::Http::Code::Ok);
    WASHAPI_LOG_REQUEST_OUT << "OK (username:" << username << ")";
}

void WashApi::UserDetails(const Net::Rest::Request &request, Net::Http::ResponseWriter response)
{
    WASHAPI_LOG_REQUEST_IN;
    WASHAPI_AUTHENTICATE;

    stUsers user;
    if(db->getUserDetails(USERID, user) == dbConnection::OK)
    {
        QJsonObject jsonObject;

        jsonObject["name"] = user.name;
        jsonObject["email"] = user.email;
        jsonObject["rating"] = user.rating;

        QJsonDocument doc(jsonObject);
        response.send(Net::Http::Code::Ok, doc.toJson(QJsonDocument::Compact).toStdString(), MIME(Application, Json));
        WASHAPI_LOG_REQUEST_OUT << "OK";
    }
    else
    {
        response.send(Net::Http::Code::Not_Found);
        WASHAPI_LOG_REQUEST_OUT << "DB_ERROR";
    }
}

void WashApi::UserReservations(const Net::Rest::Request &request, Net::Http::ResponseWriter response)
{
    WASHAPI_LOG_REQUEST_IN;
    WASHAPI_AUTHENTICATE;

    QList<stReservation> reservations;
    if(db->getReservationsForUser(USERID, &reservations) == dbConnection::OK)
    {
        QJsonArray jsonArray;

        foreach(const stReservation& reserv, reservations)
        {
            QJsonObject jsonObject;

            jsonObject["id"] = (int)reserv.id;
            jsonObject["washing_type"] = reserv.washing_type;
            jsonObject["washing_hour"] = reserv.washing_hour;
            jsonObject["status"] = (int)reserv.status;
            jsonObject["washing_block"] = (int)reserv.washing_block;
            jsonObject["id_washVendor"] = (int)reserv.id_washVendor;
            jsonObject["id_employee"] = (int)reserv.id_employee;

            jsonArray.push_back(jsonObject);
        }

        QJsonDocument doc(jsonArray);
        response.send(Net::Http::Code::Ok, doc.toJson(QJsonDocument::Compact).toStdString(), MIME(Application, Json));
        WASHAPI_LOG_REQUEST_OUT << "OK (items:" << jsonArray.count() << ")";
    }
    else
    {
        response.send(Net::Http::Code::Not_Found);
        WASHAPI_LOG_REQUEST_OUT << "DB_ERROR";
    }
}

void WashApi::AddReservation(const Net::Rest::Request &request, Net::Http::ResponseWriter response)
{
    WASHAPI_LOG_REQUEST_IN;
    WASHAPI_AUTHENTICATE;

    QJsonParseError jsonError;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(QString(request.body().c_str()).toUtf8(), &jsonError);

    if(jsonError.error != QJsonParseError::NoError)
    {
        response.send(Net::Http::Code::Bad_Request);
        WASHAPI_LOG_REQUEST_OUT << "REQUEST PARSING ERROR: " << jsonError.errorString();
        return;
    }

    QJsonObject jsonObject = jsonResponse.object();
    if(!jsonObject.contains("washvendor") || !jsonObject.contains("washtype") || !jsonObject.contains("hour"))
    {
        response.send(Net::Http::Code::Bad_Request);
        WASHAPI_LOG_REQUEST_OUT << "INVALID REQUEST";
        return;
    }

    uint vendorId = jsonObject["washvendor"].toInt();
    QString washtype = jsonObject["washtype"].toString();
    QString hour = jsonObject["hour"].toString();

    if(db->addReservation(vendorId, USERID, washtype, hour) != dbConnection::OK)
    {
        response.send(Net::Http::Code::Bad_Request);
        WASHAPI_LOG_REQUEST_OUT << "DB_ERROR - Add reservation failed";
        return;
    }

    response.send(Net::Http::Code::Ok);
    WASHAPI_LOG_REQUEST_OUT << "OK";
}

void WashApi::WashVendorList(const Net::Rest::Request &request, Net::Http::ResponseWriter response)
{
    WASHAPI_LOG_REQUEST_IN;
    WASHAPI_AUTHENTICATE;

    QList<stWashVendors> washVendors;
    if(db->getAllWashVendors(&washVendors) == dbConnection::OK)
    {
        QJsonArray jsonArray;

        foreach(const stWashVendors& vendor, washVendors)
        {
            QJsonObject jsonObject;

            jsonObject["id"] = (int)vendor.id;
            jsonObject["name"] = vendor.name;
            jsonObject["details"] = vendor.details;
            jsonObject["schedule"] = vendor.schedule;
            jsonObject["gpsLocation"] = vendor.gpsLocation;
            jsonObject["capacity"] = vendor.capacity;
            jsonObject["washingTypes"] = vendor.washingTypes;
            jsonObject["rating"] = vendor.rating;

            jsonArray.push_back(jsonObject);
        }

        QJsonDocument doc(jsonArray);
        response.send(Net::Http::Code::Ok, doc.toJson(QJsonDocument::Compact).toStdString(), MIME(Application, Json));
        WASHAPI_LOG_REQUEST_OUT << "OK (items:" << jsonArray.count() << ")";
    }
    else
    {
        response.send(Net::Http::Code::Not_Found);
        WASHAPI_LOG_REQUEST_OUT << "DB_ERROR";
    }
}

void WashApi::WashVendorPrices(const Net::Rest::Request &request, Net::Http::ResponseWriter response)
{
    uint vendorId = request.param(":vendor_id").as<uint>();

    WASHAPI_LOG_REQUEST_IN << "(vendor_id:" << vendorId << ")";
    WASHAPI_AUTHENTICATE

    QList<stPrices> pricesList;
    if(db->getPricesForWashVendor(vendorId, &pricesList) == dbConnection::OK)
    {
        QJsonArray jsonArray;

        foreach(const stPrices& price, pricesList)
        {
            QJsonObject jsonObject;

            jsonObject["id"] = (int)price.id_price;
            jsonObject["wash_type"] = price.wash_type;
            jsonObject["value"] = (int)price.value;

            jsonArray.push_back(jsonObject);
        }

        QJsonDocument doc(jsonArray);
        response.send(Net::Http::Code::Ok, doc.toJson(QJsonDocument::Compact).toStdString(), MIME(Application, Json));
        WASHAPI_LOG_REQUEST_OUT << "OK (items:" << jsonArray.count() << ")";
    }
    else
    {
        response.send(Net::Http::Code::Not_Found);
        WASHAPI_LOG_REQUEST_OUT << "DB_ERROR";
    }
}

void WashApi::WashVendorReservations(const Net::Rest::Request &request, Net::Http::ResponseWriter response)
{
    uint vendorId = request.param(":vendor_id").as<uint>();

    WASHAPI_LOG_REQUEST_IN << "(vendor_id:" << vendorId << ")";
    WASHAPI_AUTHENTICATE

    QList<stReservation> reservationList;
    if(db->getReservationsForVendor(vendorId, &reservationList) == dbConnection::OK)
    {
        QJsonArray jsonArray;

        foreach(const stReservation& reservation, reservationList)
        {
            QJsonObject jsonObject;

            jsonObject["id"] = (int)reservation.id;
            jsonObject["status"] = (int)reservation.status;
            jsonObject["washing_hour"] = reservation.washing_hour;
            jsonObject["washing_type"] = reservation.washing_type;

            jsonArray.push_back(jsonObject);
        }

        QJsonDocument doc(jsonArray);
        response.send(Net::Http::Code::Ok, doc.toJson(QJsonDocument::Compact).toStdString(), MIME(Application, Json));
        WASHAPI_LOG_REQUEST_OUT << "OK (items:" << jsonArray.count() << ")";
    }
    else
    {
        response.send(Net::Http::Code::Not_Found);
        WASHAPI_LOG_REQUEST_OUT << "DB_ERROR";
    }
}

void WashApi::EmployeeList(const Net::Rest::Request &request, Net::Http::ResponseWriter response)
{
    uint vendorId = request.param(":vendor_id").as<uint>();

    WASHAPI_LOG_REQUEST_IN << "(vendor_id:" << vendorId << ")";
    WASHAPI_AUTHENTICATE

    QList<stEmployees> employeeList;
    if(db->getEmployeesForWashVendor(vendorId, &employeeList) == dbConnection::OK)
    {
        QJsonArray jsonArray;

        foreach(const stEmployees& employee, employeeList)
        {
            QJsonObject jsonObject;

            jsonObject["id"] = (int)employee.id;
            jsonObject["name"] = employee.name;
            jsonObject["info"] = employee.info;
            jsonObject["rating"] = employee.rating;

            jsonArray.push_back(jsonObject);
        }

        QJsonDocument doc(jsonArray);
        response.send(Net::Http::Code::Ok, doc.toJson(QJsonDocument::Compact).toStdString(), MIME(Application, Json));
        WASHAPI_LOG_REQUEST_OUT << "OK (items:" << jsonArray.count() << ")";
    }
    else
    {
        response.send(Net::Http::Code::Not_Found);
        WASHAPI_LOG_REQUEST_OUT << "DB_ERROR";
    }
}
