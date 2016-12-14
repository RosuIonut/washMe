#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include <QMap>
#include <QTimer>
#include <QDateTime>
#include <QMutex>
#include <QObject>
#include <endpoint.h>

#define WASHME_AUTH_TIMEOUT    600  // 10 min
#define WASHME_AUTH_HEADER     "AuthToken"

class AuthenticationManager : public QObject
{
    Q_OBJECT

public:
    AuthenticationManager();
    virtual ~AuthenticationManager();

    QString AuthenticateUser(uint userId, const QString& username);
    uint IsAuthenticated(const QString& token);
    uint IsAuthenticated(const Net::Http::Header::Collection& headers);
    uint GetUserId(const Net::Http::Header::Collection& headers);

public slots:
    void CheckTokenTimeout();

private:
    struct Auth
    {
        uint userId;
        QString username;
        QString token;
        QDateTime timestamp;
    };

    QMap<QString, Auth> sessions;
    QMutex mutex;
    QTimer timer;
};

#endif // AUTHENTICATIONMANAGER_H
