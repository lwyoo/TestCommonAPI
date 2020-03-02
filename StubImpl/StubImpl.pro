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
    $$PWD/../src-gen/v1/proj/dcluster/McuManager/McuManagerDBusStubAdapter.cpp \
    $$PWD/../src-gen/v1/proj/dcluster/McuManager/McuManagerStubDefault.cpp \
    CommonAPIStub.cpp \
    CommonAPIStubImpl.cpp \
    MainWindowStub.cpp \
    MyQuickItemStub.cpp \
    main.cpp \

LIBS += \
    -L/opt/GENIVI/lib -lCommonAPI -lCommonAPI-DBus -ldbus-1 -ldlt

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CommonAPIStub.h \
    CommonAPIStubImpl.h \
    MyQuickItemStub.h \
    MainWindowStub.h \


