QT += quick

CONFIG += c++11

INCLUDEPATH+= \
                /opt/GENIVI/include \
                /opt/GENIVI/include/dlt \
                /opt/GENIVI/include/dbus-1.0 \
                /opt/GENIVI/include/CommonAPI-3.1 \
                /opt/GENIVI/lib/dbus-1.0/include \
                $$PWD/../src-gen \

SOURCES += \
#    TestProxyImp.cpp \
    HelloProxyMain.cpp \
                main.cpp \
                $$PWD/../src-gen/v0/commonapi/examples/HelloWorldDBusDeployment.cpp \
                $$PWD/../src-gen/v0/commonapi/examples/HelloWorldDBusProxy.cpp \
#                $$PWD/../src-gen/v1/proj/testcode/TestCodeDBusDeployment.cpp \
#                $$PWD/../src-gen/v1/proj/testcode/TestCodeDBusProxy.cpp \

LIBS += \
                -L/opt/GENIVI/lib -lCommonAPI -lCommonAPI-DBus -ldbus-1 -ldlt

RESOURCES += qml.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
 \#    TestProxyImp.h
    HelloProxyMain.h
