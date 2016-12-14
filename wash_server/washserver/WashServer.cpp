/*
 * WashServer.cpp
 *
 *  Created on: Nov 23, 2016
 *      Author: Iulian Cretu
 */

#include "WashServer.h"
#include "WashApi.h"
#include <QDebug>


WashServer::WashServer(uint16_t port, uint8_t threads) :
    washApi(new WashApi()),
    port(port)
{
    Net::Address addr(Net::Ipv4::any(), port);
    auto opts = Net::Http::Endpoint::options().threads(threads).flags(Net::Tcp::Options::None);

    Net::Http::Header::Registry::registerHeader<AuthTokenHeader>();

    httpEndpoint = std::make_shared<Net::Http::Endpoint>(addr);
    httpEndpoint->init(opts);

    SetupRoutes();
}

WashServer::~WashServer()
{
    delete washApi;
}

void WashServer::Start()
{
    httpEndpoint->setHandler(router.handler());
    httpEndpoint->serveThreaded();
    qInfo() << "WashServer started listening on" << port;
}

void WashServer::Shutdown()
{
    httpEndpoint->shutdown();
    qInfo() << "WashServer is taking a break. Have a wonderful day!";
}

void WashServer::SetupRoutes()
{
    Net::Rest::Routes::Post(router, "/api/login", Net::Rest::Routes::bind(&WashApi::Login, washApi));
    Net::Rest::Routes::Post(router, "/api/signup", Net::Rest::Routes::bind(&WashApi::Signup, washApi));
    Net::Rest::Routes::Get(router, "/api/user_details", Net::Rest::Routes::bind(&WashApi::UserDetails, washApi));

    Net::Rest::Routes::Get(router, "/api/user_reservations", Net::Rest::Routes::bind(&WashApi::UserReservations, washApi));
    Net::Rest::Routes::Post(router, "/api/add_reservation", Net::Rest::Routes::bind(&WashApi::AddReservation, washApi));

    Net::Rest::Routes::Get(router, "/api/wash_vendor_list", Net::Rest::Routes::bind(&WashApi::WashVendorList, washApi));
    Net::Rest::Routes::Get(router, "/api/wash_vendor_prices/:vendor_id", Net::Rest::Routes::bind(&WashApi::WashVendorPrices, washApi));
    Net::Rest::Routes::Get(router, "/api/wash_vendor_reservations/:vendor_id", Net::Rest::Routes::bind(&WashApi::WashVendorReservations, washApi));

    Net::Rest::Routes::Get(router, "/api/employee_list/:vendor_id", Net::Rest::Routes::bind(&WashApi::EmployeeList, washApi));

}


