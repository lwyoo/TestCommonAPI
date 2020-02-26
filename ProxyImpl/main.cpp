#include "HelloProxyMain.h"
#include "MainWindowProxy.h"
#include <QGuiApplication>
int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    MainWindowProxy::instance();

    HelloProxyMain* proxyInst = new HelloProxyMain();
    proxyInst->Init();
    proxyInst->SubscribeBroadcast();

    MainWindowProxy::instance()->show();

    return app.exec();
}
