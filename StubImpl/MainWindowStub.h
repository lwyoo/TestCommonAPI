#ifndef MainWindowStub_H
#define MainWindowStub_H

#include <QQmlContext>
#include <QQuickView>

class MainWindowStub : public QQuickView {
    Q_OBJECT

public:
    static QSharedPointer<MainWindowStub> instance(QQuickView* parent = Q_NULLPTR);
    void findChiledItem(const QString objectName);
    void destroyTest();

private:
    explicit MainWindowStub(QQuickView* parent = nullptr);

public slots:
};

#endif // MainWindowStub_H
