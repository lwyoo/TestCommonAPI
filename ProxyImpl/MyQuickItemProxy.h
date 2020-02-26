#ifndef MyQuickItemProxy_H
#define MyQuickItemProxy_H
//#include "HelloProxyMain.h"
#include <QElapsedTimer>
#include <QQuickItem>
class MyQuickItemProxy : public QQuickItem {
    Q_OBJECT

    Q_PROPERTY(int testValue READ testValue WRITE setTestValue NOTIFY testValueChanged)
public:
    static QSharedPointer<MyQuickItemProxy> instance(QQuickItem* parent = Q_NULLPTR);
    void destroyTest();
    ~MyQuickItemProxy();

    int testValue();
    void setTestValue(int value);
signals:
    void testValueChanged(int value);

private slots:
    void handleWindowChanged(QQuickWindow* win);
    void slotBeforeSynchronizing();
    void slotSceneGraphInvalidated();

    void slotBeforeRendering();
    void slotAfterRendering();
    void slotFrameSwapped();

private:
    explicit MyQuickItemProxy(QQuickItem* parent = Q_NULLPTR);

    QQuickItem* mItem;

    QElapsedTimer mTimer;

    int mVaue;

    //    HelloProxyMain* mProxy;
};

#endif // MyQuickItemProxy_H
