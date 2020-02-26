#include "HelloProxyMain.h"
#include "MainWindowProxy.h"
#include "squircle.h"
#include <QGuiApplication>
int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<Squircle>("OpenGLUnderQML", 1, 0, "Squircle");

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    MainWindowProxy::instance();

    HelloProxyMain* proxyInst = new HelloProxyMain();
    proxyInst->Init();
    proxyInst->SubscribeBroadcast();

    MainWindowProxy::instance()->show();

    return app.exec();
}
