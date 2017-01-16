/*
 * WashServer.h
 *
 *  Created on: Nov 23, 2016
 *      Author: Iulian Cretu
 */

#ifndef WASHSERVER_H_
#define WASHSERVER_H_

#include <router.h>
#include <endpoint.h>
#include <QString>

#define WASHSERVER_DEFAULT_PORT         9066
#define WASHSERVER_DEFAULT_THREADS      16
#define WASHDB_DEFAULT_PORT             3306
#define WASHDB_DRIVER                   "QMYSQL3"
#define WASHDB_USERNAME                 "washslave"
#define WASHDB_PASSWORD                 "pass1qaz"

class WashApi;

class WashServer
{
public:
    WashServer(uint16_t port = WASHSERVER_DEFAULT_PORT, uint8_t threads = WASHSERVER_DEFAULT_THREADS);
    virtual ~WashServer();

    void Start();
    void Shutdown();

    class AuthTokenHeader : public Net::Http::Header::Header
    {
    public:
        NAME("AuthToken")

        void parse(const std::string& str)  { token = str.c_str(); }
        void write(std::ostream& os) const  { os << token.toStdString(); }
        QString AuthenticationToken() const { return token; }

    private:
        QString token;
    };

    class AccessControlAllowOrigin : public Net::Http::Header::Header
    {
    public:
        NAME("Access-Control-Allow-Origin")

        AccessControlAllowOrigin(const std::string& str) { value = str.c_str(); }
        void parse(const std::string& str)  { value = str.c_str(); }
        void write(std::ostream& os) const  { os << value.toStdString(); }
        QString Value() const { return value; }

    private:
        QString value;
    };

    class AccessControlAllowMethods : public Net::Http::Header::Header
    {
    public:
        NAME("Access-Control-Allow-Methods")

        AccessControlAllowMethods(const std::string& str) { value = str.c_str(); }
        void parse(const std::string& str)  { value = str.c_str(); }
        void write(std::ostream& os) const  { os << value.toStdString(); }
        QString Value() const { return value; }

    private:
        QString value;
    };

    class AccessControlAllowHeaders : public Net::Http::Header::Header
    {
    public:
        NAME("Access-Control-Allow-Headers")

        AccessControlAllowHeaders(const std::string& str) { value = str.c_str(); }
        void parse(const std::string& str)  { value = str.c_str(); }
        void write(std::ostream& os) const  { os << value.toStdString(); }
        QString Value() const { return value; }

    private:
        QString value;
    };

private:
    void SetupRoutes();

    std::shared_ptr<Net::Http::Endpoint> httpEndpoint;
    Net::Rest::Router router;
    WashApi* washApi;
    uint16_t port;
};

#endif /* WASHSERVER_H_ */
