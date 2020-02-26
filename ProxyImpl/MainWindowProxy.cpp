#include "MainWindowProxy.h"
#include "MyQuickItemProxy.h"
#define SCREEN_INFO_X 0
#define SCREEN_INFO_Y 0
#define SCREEN_INFO_WIDTH 1000
#define SCREEN_INFO_HEIGHT 1000

static QSharedPointer<MainWindowProxy> gMainWindowProxyIstance;

QSharedPointer<MainWindowProxy> MainWindowProxy::instance(QQuickView* parent)
{
    if (gMainWindowProxyIstance.isNull()) {
        gMainWindowProxyIstance = QSharedPointer<MainWindowProxy>(new MainWindowProxy(parent));
    }

    return gMainWindowProxyIstance;
}

void MainWindowProxy::findChiledItem(const QString objectName)
{
    qDebug() << "objectName : " << objectName;

    QQuickItem* tmp = Q_NULLPTR;
    tmp = findChild<QQuickItem*>(objectName);

    if (Q_NULLPTR != tmp) {
        qDebug() << "Valied data ";
    } else {
        qDebug() << "InValied data ";
    }
}

void MainWindowProxy::destroyTest()
{
    MyQuickItemProxy::instance()->destroyTest();
}

MainWindowProxy::MainWindowProxy(QQuickView* parent)
    : QQuickView(parent)
{
    this->setColor(QColor(Qt::darkGray));
    this->setResizeMode(QQuickView::SizeViewToRootObject);
    this->setGeometry(QRect(SCREEN_INFO_X, SCREEN_INFO_Y, SCREEN_INFO_WIDTH, SCREEN_INFO_HEIGHT));
    this->setMinimumSize(QSize(SCREEN_INFO_WIDTH, SCREEN_INFO_HEIGHT));
    this->setMaximumSize(QSize(SCREEN_INFO_WIDTH, SCREEN_INFO_HEIGHT));

    rootContext()->setContextProperty("MainWindowProxy", this);
    qDebug() << "~!~~~~~~~~~~~22222222";
    rootContext()->setContextProperty("MyQuickItemProxy", MyQuickItemProxy::instance().data());
    qDebug() << "~!~~~~~~~~~~~";
}
