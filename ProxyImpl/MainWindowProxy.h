#ifndef MainWindowProxy_H
#define MainWindowProxy_H

#include <QQmlContext>
#include <QQuickView>

class MainWindowProxy : public QQuickView {
    Q_OBJECT

public:
    static QSharedPointer<MainWindowProxy> instance(QQuickView* parent = Q_NULLPTR);
    void findChiledItem(const QString objectName);
    void destroyTest();

private:
    explicit MainWindowProxy(QQuickView* parent = nullptr);

public slots:
};

#endif // MainWindowProxy_H
