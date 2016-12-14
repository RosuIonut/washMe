#include <QCoreApplication>

#include "WashServer.h"
#include "Logger.h"

#include <signal.h>
#include <unistd.h>

void catchUnixSignals(const std::vector<int>& quitSignals, const std::vector<int>& ignoreSignals = std::vector<int>())
{
    auto handler = [](int sig) ->void
    {
        printf("\nQuit the application (user request signal = %d).\n", sig);
        QCoreApplication::quit();
    };

    // all these signals will be ignored.
    for ( int sig : ignoreSignals )
        signal(sig, SIG_IGN);

    // each of these signals calls the handler (quits the QCoreApplication).
    for ( int sig : quitSignals )
        signal(sig, handler);
}


int main(int argc, char *argv[])
{
    if(argc == 2)
        Logger::Init(argv[1]);
    else
        Logger::Init();

    QCoreApplication app(argc, argv);

    WashServer server;
    server.Start();

    catchUnixSignals({SIGQUIT, SIGINT, SIGTERM, SIGHUP, SIGTSTP});

    app.exec();
    server.Shutdown();

    return 0;
}
