#include "MyQuickItemStub.h"
#include <QDebug>
#include <QGuiApplication>
#include <QQmlIncubator>
#include <QQuickView>

static QSharedPointer<MyQuickItemStub> gMyQuickItemStubIstance;

QSharedPointer<MyQuickItemStub> MyQuickItemStub::instance(QQuickItem* parent)
{
    if (gMyQuickItemStubIstance.isNull()) {
        gMyQuickItemStubIstance = QSharedPointer<MyQuickItemStub>(new MyQuickItemStub(parent));
    }

    return gMyQuickItemStubIstance;
}

void MyQuickItemStub::destroyTest()
{
    mItem->setEnabled(false);
    this->deleteLater();
}

MyQuickItemStub::~MyQuickItemStub()
{
}

void MyQuickItemStub::testFunction(int value)
{
    qDebug() << Q_FUNC_INFO;

    setTestValue(value);
    mStub->testFunction(testValue());
}

int MyQuickItemStub::testValue()
{
    return mVaue;
}

void MyQuickItemStub::setTestValue(int value)
{
    mVaue = value;
}

void MyQuickItemStub::handleWindowChanged(QQuickWindow* win)
{
    qDebug() << Q_FUNC_INFO;

    if (win) {
        qDebug() << " handleWindowChanged window is valid";
        connect(win, &QQuickWindow::beforeSynchronizing, this, &MyQuickItemStub::slotBeforeSynchronizing, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::sceneGraphInvalidated, this, &MyQuickItemStub::slotSceneGraphInvalidated, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::beforeRendering, this, &MyQuickItemStub::slotBeforeRendering, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::afterRendering, this, &MyQuickItemStub::slotAfterRendering, Qt::DirectConnection);
        //        connect(win, &QQuickWindow::frameSwapped, this, &MyQuickItemStub::slotFrameSwapped, Qt::DirectConnection);
        win->setClearBeforeRendering(false);
    }
}

void MyQuickItemStub::slotBeforeSynchronizing()
{
    qDebug() << Q_FUNC_INFO;
    mTimer.restart();
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItemStub::slotSceneGraphInvalidated()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItemStub::slotBeforeRendering()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItemStub::slotAfterRendering()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

void MyQuickItemStub::slotFrameSwapped()
{
    qDebug() << Q_FUNC_INFO;
    qDebug() << "duration time : " << mTimer.elapsed() << "milliseconds";
}

MyQuickItemStub::MyQuickItemStub(QQuickItem* parent)
    : QQuickItem(parent)
    , mItem(nullptr)
{
    QWindowList windowList = qApp->allWindows();
    connect(this, &QQuickItem::windowChanged, this, &MyQuickItemStub::handleWindowChanged);
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
