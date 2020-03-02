#include "CommonAPIProxy.h"
#include <CommonAPI/CommonAPI.hpp>
#include <QDebug>
CommonAPIProxy::CommonAPIProxy()
    : mCommonAPIProxy(nullptr)
{
}

void CommonAPIProxy::Init()
{
    std::string domain = "local";
    std::string instance = "commonapi.examples.HelloWorld";
    std::string connection = "client-sample";
    mCommonAPIProxy = CommonAPI::Runtime::get()->buildProxy<v1::proj::dcluster::McuManager::McuManagerProxy>(domain, instance, connection);

    if (nullptr == mCommonAPIProxy) {
        std::cerr << "Can't build proxy!" << std::endl;
        return;
    }

    //    while (!mMyProxy->isAvailable()) {
    //        std::this_thread::sleep_for(std::chrono::microseconds(10));
    //    }

    std::cout << "Connection Established!" << std::endl;

    const std::string name = "World";
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    //    mCommonAPIProxy->sayHello(name, callStatus, returnMessage);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call failed!\n";
        return;
    }
    std::cout << "Got message: ’" << returnMessage << "’\n";
}

void CommonAPIProxy::InitAsync()
{
    std::string domain = "local";
    std::string instance = "commonapi.examples.HelloWorld";
    std::string connection = "client-sample";
    mCommonAPIProxy = CommonAPI::Runtime::get()->buildProxy<v1::proj::dcluster::McuManager::McuManagerProxy>(domain, instance, connection);

    if (nullptr != mCommonAPIProxy) {
        std::cerr << "build proxy!" << std::endl;
        mCommonAPIProxy->getProxyStatusEvent().subscribe(std::bind(&CommonAPIProxy::callbackConnectionStatusChanged, this, std::placeholders::_1));
    } else {
        std::cerr << "Can't build proxy!" << std::endl;
        return;
    }
}

void CommonAPIProxy::callbackConnectionStatusChanged(CommonAPI::AvailabilityStatus _status)
{
    if (CommonAPI::AvailabilityStatus::AVAILABLE == _status) {
        std::cout << "proxy status : Available!\n";

        //fidl attribute init
        bool bAttrSubscription = SubscribeStubAttributeChagedEvent();
        SubscribeBroadcast();

        const std::string name = "World";
        CommonAPI::CallStatus callStatus;
        std::string returnMessage = "";

        CommonAPI::CallInfo callInfo(10000);
        // method sync call
        //        mMyProxy->sayHello(name, callStatus, returnMessage, &callInfo);

        if (callStatus != CommonAPI::CallStatus::SUCCESS) {
            std::cerr << "Remote call failed!\n";
            return;
        }
        std::cout << "Got message: ’" << returnMessage << "’\n";

        //method aync call
        //        mMyProxy->sayHelloAsync("World Async", &sayHelloAsyncCallback, &callInfo);

        //attribute test
        if (true == bAttrSubscription) {
            printAttributeValue();
        }
    } else {
        std::cout << "proxy status : Not available!\n";
    }
}

bool CommonAPIProxy::SubscribeBroadcast()
{
    QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO;
    static bool once = true;
    bool ret = false;

    if (true == once) {
        if (nullptr == mCommonAPIProxy) {
            QDebug(QtMsgType::QtInfoMsg) << "Proxy instance is nullptr!";
            ret = false;
        }

        if (false == mCommonAPIProxy->isAvailable()) {
            QDebug(QtMsgType::QtInfoMsg) << "Proxy instance is not available now!";
            ret = false;
        }

        QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "broadcast callback setting~~~~~~~~~~~~~~~";
        //        mMyProxy->getMyStatusEvent().subscribe(std::bind(&HelloProxyMain::cbMyStatus, this, std::placeholders::_1));
        //        mMyProxy->getMyEventEvent().subscribe(std::bind(&HelloProxyMain::callbackMyEventChanged, this, std::placeholders::_1));
        once = false;
        ret = true;
        QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << " success!";
    }
    return ret;
}

bool CommonAPIProxy::SubscribeStubAttributeChagedEvent()
{
    static bool once = true;
    bool ret = false;

    if (true == once) {
        if (nullptr == mCommonAPIProxy) {
            QDebug(QtMsgType::QtInfoMsg) << "Proxy instance is nullptr!";
            ret = false;
        }

        if (false == mCommonAPIProxy->isAvailable()) {
            QDebug(QtMsgType::QtInfoMsg) << "Proxy instance is not available now!";
            ret = false;
        }

        mCommonAPIProxy->getAdasInfoAttribute().getChangedEvent().subscribe(std::bind(&CommonAPIProxy::callbackAdasInfoAttributeChanged, this, std::placeholders::_1));

        once = false;
        ret = true;
        QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << " success!";
    }
    return ret;
}

void CommonAPIProxy::callbackAdasInfoAttributeChanged(const v1::proj::dcluster::McuManager::McuManagerTypes::StAdasInfo& _value)
{
    qDebug() << Q_FUNC_INFO;
    printStAdasInfo(_value);
}

void CommonAPIProxy::printAttributeValue()
{
    CommonAPI::CallStatus callStatus;
    MCUManagerType::StAdasInfo tempValue;
    int retXAttrValue = 0;

    //get x attribute sync
    mCommonAPIProxy->getAdasInfoAttribute().getValue(callStatus, tempValue);
    if (callStatus == CommonAPI::CallStatus::SUCCESS) {
        QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "Current Stub x Attr value = " << retXAttrValue;
        printStAdasInfo(tempValue);
    }
    //get x attribute async
    //    mCommonAPIProxy->getAdasInfoAttribute().getValueAsync(callStatus, tempValue);

    mCommonAPIProxy->getAdasInfoAttribute().getValueAsync([&](const CommonAPI::CallStatus& callStatus, MCUManagerType::StAdasInfo tempValue2) {
        if (callStatus == CommonAPI::CallStatus::SUCCESS) {
            printStAdasInfo(tempValue2);
        }
    });
}

void CommonAPIProxy::printStAdasInfo(const MCUManagerType::StAdasInfo& _value)
{
    QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value size : " << _value.getVehicle_info_list().size();

    QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value.getDisp_type(); : " << _value.getDisp_type();

    if (_value.getVehicle_info_list().size() != 0) {
        for (unsigned int i = 0; i < _value.getVehicle_info_list().size(); i++) {

            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value[" << i << "] _value.getVehicle_info_list().at(i).getVehicle_info().getX();     : " << _value.getVehicle_info_list().at(i).getVehicle_info().getX();
            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value[" << i << "] _value.getVehicle_info_list().at(i).getVehicle_info().getY();     : " << _value.getVehicle_info_list().at(i).getVehicle_info().getY();
            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value[" << i << "] _value.getVehicle_info_list().at(i).getVehicle_info().getScale(); : " << _value.getVehicle_info_list().at(i).getVehicle_info().getScale();

            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value[" << i << "] getVehicle_id() : " << _value.getVehicle_info_list().at(i).getVehicle_id();
            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value[" << i << "] getVehicle_status() : " << _value.getVehicle_info_list().at(i).getVehicle_status();
            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value[" << i << "] getVehicle_info().getScale() : " << _value.getVehicle_info_list().at(i).getVehicle_info().getScale();
            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value[" << i << "] getVehicle_info().getX() : " << _value.getVehicle_info_list().at(i).getVehicle_info().getX();
            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "_value[" << i << "] getVehicle_info().getY() : " << _value.getVehicle_info_list().at(i).getVehicle_info().getY();
        }
    }

    qDebug() << Q_FUNC_INFO << "getL_lane_x();           : " << _value.getLane_info().getL_lane_x();
    qDebug() << Q_FUNC_INFO << "getR_lane_x();           : " << _value.getLane_info().getR_lane_x();
    qDebug() << Q_FUNC_INFO << "getLane_type();          : " << _value.getLane_info().getLane_type();
    qDebug() << Q_FUNC_INFO << "getL_lca_status();       : " << _value.getLane_info().getL_lca_status();
    qDebug() << Q_FUNC_INFO << "getR_lca_status();       : " << _value.getLane_info().getR_lca_status();
    qDebug() << Q_FUNC_INFO << "getLane_curve_ratio();   : " << _value.getLane_info().getLane_curve_ratio();
    qDebug() << Q_FUNC_INFO << "getLane_active_status(); : " << _value.getLane_info().getLane_active_status();
}
