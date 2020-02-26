#include "MyQuickItemProxy.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQmlIncubator>
#include <QQuickView>

static QSharedPointer<MyQuickItemProxy> gMyQuickItemProxyIstance;

QSharedPointer<MyQuickItemProxy> MyQuickItemProxy::instance(QQuickItem* parent)
{
    if (gMyQuickItemProxyIstance.isNull()) {
        gMyQuickItemProxyIstance = QSharedPointer<MyQuickItemProxy>(new MyQuickItemProxy(parent));
    }

    return gMyQuickItemProxyIstance;
}

void MyQuickItemProxy::destroyTest()
{
    mItem->setEnabled(false);
    this->deleteLater();
}

MyQuickItemProxy::~MyQuickItemProxy()
{
}

int MyQuickItemProxy::testValue()
{
    return mVaue;
}

void MyQuickItemProxy::setTestValue(int value)
{
    qDebug() << Q_FUNC_INFO << "value : " << value;
    mVaue = value;
    emit testValueChanged(mVaue);
}

void MyQuickItemProxy::handleWindowChanged(QQuickWindow* win)
{
    qDebug() << Q_FUNC_INFO;

    if (win) {
        qDebug() << " handleWindowChanged window is valid";
        connect(win, &QQuickWindow::beforeSynchronizing, this, &MyQuickItemProxy::slotBeforeSynchronizing, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &MyQuickItemProxy::slotSceneGraphInvalidated, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::beforeRendering, this, &MyQuickItemProxy::slotBeforeRendering, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::afterRendering, this, &MyQuickItemProxy::slotAfterRendering, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::frameSwapped, this, &MyQuickItemProxy::slotFrameSwapped, Qt::DirectConnection);
        win->setClearBeforeRendering(false);
    }
}

void MyQuickItemProxy::slotBeforeSynchronizing()
{
    qDebug() << Q_FUNC_INFO;
    mTimer.restart();
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItemProxy::slotSceneGraphInvalidated()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItemProxy::slotBeforeRendering()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItemProxy::slotAfterRendering()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItemProxy::slotFrameSwapped()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

MyQuickItemProxy::MyQuickItemProxy(QQuickItem* parent)
    : QQuickItem(parent)
    , mItem(nullptr)
{
    qDebug() << Q_FUNC_INFO;
    QWindowList windowList = qApp->allWindows();
    connect(this, &QQuickItem::windowChanged, this, &MyQuickItemProxy::handleWindowChanged);
    qDebug() << "windowList count : " << windowList.count();

    //    mProxy = new HelloProxyMain();
    //    mProxy->Init();

    if (windowList.count() > 0) {
        const QQuickView* view = qobject_cast<QQuickView*>(windowList.at(0));
        QQmlEngine* engine = view->engine();

        QQmlComponent component(engine, QUrl("qrc:/main.qml"));
        mItem = qobject_cast<QQuickItem*>(component.create());

        if (mItem) {
            mItem->setParent(this);
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
    qDebug() << Q_FUNC_INFO << "end";
}
