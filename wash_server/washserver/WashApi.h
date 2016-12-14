#ifndef WASHAPI_H
#define WASHAPI_H

#include <endpoint.h>
#include <router.h>

class dbConnection;
class AuthenticationManager;

class WashApi
{
public:
    WashApi();

    void Signup(const Net::Rest::Request &request, Net::Http::ResponseWriter response);
    void Login(const Net::Rest::Request &request, Net::Http::ResponseWriter response);

    void UserDetails(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void UserReservations(const Net::Rest::Request &request, Net::Http::ResponseWriter response);
    void AddReservation(const Net::Rest::Request &request, Net::Http::ResponseWriter response);

    void WashVendorList(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void WashVendorPrices(const Net::Rest::Request& request, Net::Http::ResponseWriter response);
    void WashVendorReservations(const Net::Rest::Request &request, Net::Http::ResponseWriter response);

    void EmployeeList(const Net::Rest::Request& request, Net::Http::ResponseWriter response);


private:
    dbConnection *db;
    AuthenticationManager *authManager;
};

#endif // WASHAPI_H
