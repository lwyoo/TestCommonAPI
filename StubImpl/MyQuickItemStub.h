#ifndef MyQuickItemStub_H
#define MyQuickItemStub_H
#include "HelloStubMain.h"
#include <QElapsedTimer>
#include <QQuickItem>
class MyQuickItemStub : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(int testValue READ testValue WRITE setTestValue)

public:
    static QSharedPointer<MyQuickItemStub> instance(QQuickItem* parent = Q_NULLPTR);
    void destroyTest();
    ~MyQuickItemStub();

    Q_INVOKABLE void testFunction(int value);

    int testValue();
    void setTestValue(int value);

private slots:
    void handleWindowChanged(QQuickWindow* win);
    void slotBeforeSynchronizing();
    void slotSceneGraphInvalidated();

    void slotBeforeRendering();
    void slotAfterRendering();
    void slotFrameSwapped();

private:
    explicit MyQuickItemStub(QQuickItem* parent = Q_NULLPTR);

    QQuickItem* mItem;

    QElapsedTimer mTimer;

    HelloStubMain* mStub;

    int mVaue;
};

#endif // MyQuickItemStub_H
