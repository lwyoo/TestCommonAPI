#include "MyQuickItem.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQmlIncubator>
#include <QQuickView>

static QSharedPointer<MyQuickItem> gMyQuickItemIstance;

QSharedPointer<MyQuickItem> MyQuickItem::instance(QQuickItem* parent)
{
    if (gMyQuickItemIstance.isNull()) {
        gMyQuickItemIstance = QSharedPointer<MyQuickItem>(new MyQuickItem(parent));
    }

    return gMyQuickItemIstance;
}

void MyQuickItem::destroyTest()
{
    mItem->setEnabled(false);
    this->deleteLater();
}

MyQuickItem::~MyQuickItem()
{
}

void MyQuickItem::testFunction()
{
    qDebug() << Q_FUNC_INFO;
    mStub->testFunction();
}

void MyQuickItem::handleWindowChanged(QQuickWindow* win)
{
    qDebug() << Q_FUNC_INFO;

    if (win) {
        qDebug() << " handleWindowChanged window is valid";
        connect(win, &QQuickWindow::beforeSynchronizing, this, &MyQuickItem::slotBeforeSynchronizing, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &MyQuickItem::slotSceneGraphInvalidated, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::beforeRendering, this, &MyQuickItem::slotBeforeRendering, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::afterRendering, this, &MyQuickItem::slotAfterRendering, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::frameSwapped, this, &MyQuickItem::slotFrameSwapped, Qt::DirectConnection);
        win->setClearBeforeRendering(false);
    }
}

void MyQuickItem::slotBeforeSynchronizing()
{
    qDebug() << Q_FUNC_INFO;
    mTimer.restart();
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItem::slotSceneGraphInvalidated()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItem::slotBeforeRendering()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItem::slotAfterRendering()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItem::slotFrameSwapped()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

MyQuickItem::MyQuickItem(QQuickItem* parent)
    : QQuickItem(parent)
    , mItem(nullptr)
{
    QWindowList windowList = qApp->allWindows();
    connect(this, &QQuickItem::windowChanged, this, &MyQuickItem::handleWindowChanged);
    qDebug() << "windowList count : " << windowList.count();
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";

    mStub = new HelloStubMain();
    mStub->Init();

    if (windowList.count() > 0) {
        const QQuickView* view = qobject_cast<QQuickView*>(windowList.at(0));
        QQmlEngine* engine = view->engine();
        //        QQmlComponent component(engine, QUrl("qrc:/main.qml"));

        QQmlComponent component(engine, QUrl("qrc:/main.qml"));
        mItem = qobject_cast<QQuickItem*>(component.create());

        if (mItem) {
            mItem->setParent(this);
            //this->setParent(view->contentItem()->parent());
            mItem->setParentItem(this);
            this->setParentItem(view->contentItem());
            this->setWidth(mItem->width());
            this->setHeight(mItem->height());

            this->setEnabled(true);

            mItem->setZ(10);
            qDebug() << "Component setting is sucess [OK]";
        } else {
            qDebug() << "Component is nullptr [ERROR]";
        }

    } else {
        qDebug() << "window size is 0 [ERROR]";
    }
    mTimer.start();
}
