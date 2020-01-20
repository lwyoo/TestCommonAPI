//#include "TestProxyImp.h"
#include "HelloProxyMain.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject* obj, const QUrl& objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    HelloProxyMain* proxyInst = new HelloProxyMain();
    //    proxyInst->Init();
    proxyInst->InitAsync();

    proxyInst->SubscribeBroadcast();

    //    TestProxyImp* temp = new TestProxyImp();
    //    temp->Init();

    return app.exec();
}
