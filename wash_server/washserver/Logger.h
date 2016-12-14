#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QMutex>

class QTextStream;
class QFile;

#define WASHAPI_LOG_REQUEST_IN      qInfo().nospace() << "[REQ >>] API::" << __func__ << " "
#define WASHAPI_LOG_REQUEST_OUT     qInfo().nospace() << "[RES <<] API::" << __func__ << " "

class Logger
{
public:
    static void Init();
    static void Init(QString fileName);
    static void LogOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private:
    static QTextStream logStream;
    static QFile logFile;
    static QMutex logStreamMutex;
};

#endif // LOGGER_H
