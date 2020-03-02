TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS += \
    StubImpl \
    ProxyImpl \

DISTFILES += \
    fidl/McuManager.fidl \
    fidl/McuManagerTypes.fidl

