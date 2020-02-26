#include "MainWindowStub.h"
#include "MyQuickItem.h"
#define SCREEN_INFO_X 0
#define SCREEN_INFO_Y 0
#define SCREEN_INFO_WIDTH 1000
#define SCREEN_INFO_HEIGHT 1000

static QSharedPointer<MainWindowStub> gMainWindowStubIstance;

QSharedPointer<MainWindowStub> MainWindowStub::instance(QQuickView* parent)
{
    if (gMainWindowStubIstance.isNull()) {
        gMainWindowStubIstance = QSharedPointer<MainWindowStub>(new MainWindowStub(parent));
    }

    return gMainWindowStubIstance;
}

void MainWindowStub::findChiledItem(const QString objectName)
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

void MainWindowStub::destroyTest()
{
    MyQuickItem::instance()->destroyTest();
}

MainWindowStub::MainWindowStub(QQuickView* parent)
    : QQuickView(parent)
{
    this->setColor(QColor(Qt::darkGray));
    this->setResizeMode(QQuickView::SizeViewToRootObject);
    this->setGeometry(QRect(SCREEN_INFO_X, SCREEN_INFO_Y, SCREEN_INFO_WIDTH, SCREEN_INFO_HEIGHT));
    this->setMinimumSize(QSize(SCREEN_INFO_WIDTH, SCREEN_INFO_HEIGHT));
    this->setMaximumSize(QSize(SCREEN_INFO_WIDTH, SCREEN_INFO_HEIGHT));

    rootContext()->setContextProperty("MainWindowStub", this);
    this->rootContext()->setContextProperty("MyQuickItem", MyQuickItem::instance().data());
}
