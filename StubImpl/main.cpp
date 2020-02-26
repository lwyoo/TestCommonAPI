#include "MainWindowStub.h"
#include <QGuiApplication>
int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    MainWindowStub::instance();
    MainWindowStub::instance()->show();

    MainWindowStub::instance()->findChiledItem("dldyddn");

    return app.exec();
}
