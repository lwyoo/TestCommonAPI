#ifndef MYQUICKITEM_H
#define MYQUICKITEM_H
#include "HelloStubMain.h"
#include <QElapsedTimer>
#include <QQuickItem>
class MyQuickItem : public QQuickItem {
    Q_OBJECT
public:
    static QSharedPointer<MyQuickItem> instance(QQuickItem* parent = Q_NULLPTR);
    void destroyTest();
    ~MyQuickItem();

    Q_INVOKABLE void testFunction();

private slots:
    void handleWindowChanged(QQuickWindow* win);
    void slotBeforeSynchronizing();
    void slotSceneGraphInvalidated();

    void slotBeforeRendering();
    void slotAfterRendering();
    void slotFrameSwapped();

private:
    explicit MyQuickItem(QQuickItem* parent = Q_NULLPTR);

    QQuickItem* mItem;

    QElapsedTimer mTimer;

    HelloStubMain* mStub;
};

#endif // MYQUICKITEM_H
