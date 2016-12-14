#include "AuthenticationManager.h"
#include "WashServer.h"
#include <QMutexLocker>
#include <QUuid>
#include <QDebug>


AuthenticationManager::AuthenticationManager()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(CheckTokenTimeout()));
    timer.start(30000); // every half minute
}

AuthenticationManager::~AuthenticationManager()
{

}

QString AuthenticationManager::AuthenticateUser(uint userId, const QString &username)
{
    QMutexLocker locker(&mutex);

    for(auto it = sessions.begin(); it != sessions.end(); ++it)
    {
        if(it.value().userId == userId)
        {
            sessions.erase(it);
            break;
        }
    }

    QString token = "WASH_TK_" + QString::number(userId) + "_" + QUuid::createUuid().toString();
    sessions.insert(token, {userId, username, token, QDateTime::currentDateTime()});

    return token;
}

uint AuthenticationManager::IsAuthenticated(const QString &token)
{
    QMutexLocker locker(&mutex);

    auto it = sessions.find(token);
    if(it == sessions.end())
    {
        return 0;
    }

    if(QDateTime::currentDateTime().toMSecsSinceEpoch() - it.value().timestamp.toMSecsSinceEpoch() > WASHME_AUTH_TIMEOUT * 1000)
    {
        sessions.erase(it);
        return 0;
    }

    it.value().timestamp = QDateTime::currentDateTime();
    return it.value().userId;;
}

uint AuthenticationManager::IsAuthenticated(const Net::Http::Header::Collection &headers)
{
    if(!headers.has("AuthToken"))
    {
        qWarning().nospace() << "AuthenticationManager: Http headers doesn't contain AuthToken";
        return 0;
    }

    auto authHeader = std::dynamic_pointer_cast<const WashServer::AuthTokenHeader>(headers.get(WASHME_AUTH_HEADER));
    if(authHeader == nullptr)
        return 0;

    return IsAuthenticated(authHeader->AuthenticationToken());
}

uint AuthenticationManager::GetUserId(const Net::Http::Header::Collection &headers)
{
    if(!headers.has("AuthToken"))
    {
        qWarning().nospace() << "AuthenticationManager: Http headers doesn't contain AuthToken";
        return 0;
    }

    auto authHeader = std::dynamic_pointer_cast<const WashServer::AuthTokenHeader>(headers.get(WASHME_AUTH_HEADER));
    if(authHeader == nullptr)
        return 0;

    QMutexLocker locker(&mutex);

    auto it = sessions.find(authHeader->AuthenticationToken());
    if(it == sessions.end())
    {
        return 0;
    }

    return it.value().userId;
}

void AuthenticationManager::CheckTokenTimeout()
{
    QMutexLocker locker(&mutex);

    for(auto it = sessions.begin(); it != sessions.end(); )
    {
        if(QDateTime::currentDateTime().toMSecsSinceEpoch() - it.value().timestamp.toMSecsSinceEpoch() > WASHME_AUTH_TIMEOUT * 1000)
        {
            qInfo().nospace() << "AuthenticationManager: session expired (username:" << it.value().username << ")";
            it = sessions.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
