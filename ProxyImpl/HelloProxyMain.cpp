#include "HelloProxyMain.h"
#include <CommonAPI/CommonAPI.hpp>
#include <QDebug>
#include <QElapsedTimer>
#include <iostream>
#include <string>
#include <unistd.h>

void sayHelloAsyncCallback(const CommonAPI::CallStatus& callStatus, const std::string& returnMessage)
{
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call failed!\n";
        return;
    }
    std::cout << "Async Got message: ’" << returnMessage << "’\n";
}

HelloProxyMain::HelloProxyMain()
    : mMyProxy(nullptr)
    , mProxyX(0)
{
}

void HelloProxyMain::Init()
{
    std::string domain = "local";
    std::string instance = "commonapi.examples.HelloWorld";
    std::string connection = "client-sample";
    mMyProxy = CommonAPI::Runtime::get()->buildProxy<v0::commonapi::examples::HelloWorldProxy>(domain, instance, connection);

    if (nullptr == mMyProxy) {
        std::cerr << "Can't build proxy!" << std::endl;
        return;
    }

    while (!mMyProxy->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

    std::cout << "Connection Established!" << std::endl;

    const std::string name = "World";
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    mMyProxy->sayHello(name, callStatus, returnMessage);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call failed!\n";
        return;
    }
    std::cout << "Got message: ’" << returnMessage << "’\n";
}

void HelloProxyMain::InitAsync()
{
    std::string domain = "local";
    std::string instance = "commonapi.examples.HelloWorld";
    std::string connection = "client-sample";
    mMyProxy = CommonAPI::Runtime::get()->buildProxy<v0::commonapi::examples::HelloWorldProxy>(domain, instance, connection);

    if (nullptr != mMyProxy) {
        mMyProxy->getProxyStatusEvent().subscribe(std::bind(&HelloProxyMain::callbackConnectionStatusChanged, this, std::placeholders::_1));
    } else {
        std::cerr << "Can't build proxy!" << std::endl;
        return;
    }
}

void HelloProxyMain::callbackConnectionStatusChanged(CommonAPI::AvailabilityStatus _status)
{
    if (CommonAPI::AvailabilityStatus::AVAILABLE == _status) {
        std::cout << "proxy status : Available!\n";

        //fidl attribute init
        bool bAttrSubscription = SubscribeStubAttributeChagedEvent();

        const std::string name = "World";
        CommonAPI::CallStatus callStatus;
        std::string returnMessage;

        QElapsedTimer timer;
        // method sync call
        timer.start();
        mMyProxy->sayHello(name, callStatus, returnMessage);
        double elapsedSec = static_cast<double>(timer.elapsed()) / 1000.;
        std::cout << "sayHello() sync called! Time : " << elapsedSec << " sec elapsed." << std::endl;

        if (callStatus != CommonAPI::CallStatus::SUCCESS) {
            std::cerr << "Remote call failed!\n";
            return;
        }
        std::cout << "Got message: ’" << returnMessage << "’\n";

        //method aync call
        timer.restart();
        mMyProxy->sayHelloAsync("World Async", &sayHelloAsyncCallback);
        std::cout << "sayHello() async called! Time : " << timer.elapsed() << " milliseconds elapsed." << std::endl;

        //attribute test
        if (true == bAttrSubscription) {
            testAttributeValue();
        }
    } else {
        std::cout << "proxy status : Not available!\n";
    }
}

bool HelloProxyMain::SubscribeStubAttributeChagedEvent()
{
    static bool once = true;
    bool ret = false;

    if (true == once) {
        if (nullptr == mMyProxy) {
            QDebug(QtMsgType::QtInfoMsg) << "Proxy instance is nullptr!";
            ret = false;
        }

        if (false == mMyProxy->isAvailable()) {
            QDebug(QtMsgType::QtInfoMsg) << "Proxy instance is not available now!";
            ret = false;
        }

        mMyProxy->getXAttribute().getChangedEvent().subscribe(std::bind(&HelloProxyMain::XValueChanged, this, std::placeholders::_1));
        once = false;
        ret = true;
        QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << " success!";
    }
    return ret;
}

void HelloProxyMain::testAttributeValue()
{
    CommonAPI::CallStatus callStatus;
    int retXAttrValue = 0;

    //    //get x attribute sync
    //    mMyProxy->getXAttribute().getValue(callStatus, retXAttrValue);
    //    if (callStatus == CommonAPI::CallStatus::SUCCESS) {
    //        QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "Current Stub x Attr value = " << retXAttrValue;
    //    }
    //    //get x attribute async
    //    mMyProxy->getXAttribute().getValueAsync([&](const CommonAPI::CallStatus& callStatus, int32_t x) {
    //        if (callStatus == CommonAPI::CallStatus::SUCCESS) {
    //            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "get Stub x Attr value async = " << x;
    //        }
    //    });

    int reqXAttrValue = 10;
    int settedXAttrValue = 0;
    //set x attribue sync version
    mMyProxy->getXAttribute().setValue(reqXAttrValue, callStatus, settedXAttrValue);
    if (callStatus == CommonAPI::CallStatus::SUCCESS) {
        QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "request Sutb x Attr value = " << reqXAttrValue << ", and setted Stub x Attr value = " << settedXAttrValue;
    }

    //    //set x attribute async
    //    reqXAttrValue = 2020;
    //    mMyProxy->getXAttribute().setValueAsync(reqXAttrValue, [&](const CommonAPI::CallStatus& callStatus, int32_t x) {
    //        if (callStatus == CommonAPI::CallStatus::SUCCESS) {
    //            QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << "[Async]]setted Stub x Attr value = " << x;
    //        }
    //    });
}

void HelloProxyMain::XValueChanged(const int32_t& x)
{
    QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << " x value changed to " << x;
}
