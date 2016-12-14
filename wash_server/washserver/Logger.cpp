#include "Logger.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <QThread>
#include <QMutex>


QFile Logger::logFile;
QTextStream Logger::logStream(stdout, QIODevice::WriteOnly);
QMutex Logger::logStreamMutex;

void Logger::Init()
{
    qInstallMessageHandler(Logger::LogOutput);
}

void Logger::Init(QString fileName)
{
    //QString fileName = QCoreApplication::applicationFilePath().replace(".exe", ".log");
    logFile.setFileName(fileName);

    if (logFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        logStream.setDevice(&logFile);
        qInstallMessageHandler(Logger::LogOutput);
    }
    else
    {
        qCritical() << "Logger::Init() Error opening log file '" << fileName << "'. All debug output redirected to console. " << logFile.errorString();
    }
}

void Logger::LogOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString msgType;
    switch (type)
    {
    case QtDebugMsg:
        msgType = "[DEBUG]";
        break;
    case QtWarningMsg:
        msgType = "[WARN] ";
        break;
    case QtCriticalMsg:
        msgType = "[ERROR]";
        break;
    case QtFatalMsg:
        msgType = "[FATAL]";
        break;
    case QtInfoMsg:
        msgType = "[INFO] ";
        break;
    }

    QMutexLocker locker(&logStreamMutex);
    logStream << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " "
              << "[" << QThread::currentThreadId() << "] "
              << msgType << " "
              << msg << endl;
}

