QT += quick

CONFIG += c++11

RESOURCES += qml.qrc

INCLUDEPATH+= \
                /opt/GENIVI/include \
                /opt/GENIVI/include/dlt \
                /opt/GENIVI/include/dbus-1.0 \
                /opt/GENIVI/include/CommonAPI-3.1 \
                /opt/GENIVI/lib/dbus-1.0/include \
                $$PWD/../src-gen \

SOURCES += \
#    $$PWD/../src-gen/v0/commonapi/examples/HelloWorldDBusDeployment.cpp \
    $$PWD/../src-gen/v0/commonapi/examples/HelloWorldDBusStubAdapter.cpp \
    $$PWD/../src-gen/v0/commonapi/examples/HelloWorldStubDefault.cpp \
    HelloStubImpl.cpp \
    HelloStubMain.cpp \
#    TestStubImp.cpp \
                main.cpp \
#                $$PWD/../src-gen/v1/proj/testcode/TestCodeDBusDeployment.cpp \
#                $$PWD/../src-gen/v1/proj/testcode/TestCodeStubDefault.cpp \
#                $$PWD/../src-gen/v1/proj/testcode/TestCodeDBusStubAdapter.cpp \

LIBS += \
                -L/opt/GENIVI/lib -lCommonAPI -lCommonAPI-DBus -ldbus-1 -ldlt

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    HelloStubImpl.h \
    HelloStubMain.h \
#    TestStubImp.h
