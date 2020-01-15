#include "TestProxyImp.h"
#include <CommonAPI/CommonAPI.hpp>
#include <iostream>

TestProxyImp::TestProxyImp()
    : mTestProxy(nullptr)
{
}

void TestProxyImp::Init()
{
    mTestProxy = CommonAPI::Runtime::get()->buildProxy<v1::proj::testcode::TestCodeProxy>("local", "proj.testCode");
    if (nullptr != mTestProxy) {
        mTestProxy->getProxyStatusEvent().subscribe(
            std::bind(&TestProxyImp::callbackConnectionStatusChanged, this, std::placeholders::_1));
    }
}

void TestProxyImp::setSpeedType(int speedType)
{
}

int TestProxyImp::getSpeedType()
{
}

void TestProxyImp::setSpeedValue(int speedValue)
{
}

int TestProxyImp::getSpeedValue()
{
}

void TestProxyImp::initProxyCallback()
{
    if (nullptr != mTestProxy) {

    } else {
        std::cout << "mTestProxy is nullptr [ERROR] " << std::endl;
        return;
    }

    if (true == mTestProxy->isAvailable()) {

    } else {
        std::cout << "mTestProxy is Available [ERROR] " << std::endl;
    }

    //    // set callback !!!!!!
    //    mTestProxy->getSpeedTypeAttribute().subscribe(
    //                std::bind(&CallBackTrip::callbackTripCommonInfoAttributeChanged, m_callbackTrip, std::placeholders::_1));

    //)
}

void TestProxyImp::callbackConnectionStatusChanged(CommonAPI::AvailabilityStatus _status)
{
    if (CommonAPI::AvailabilityStatus::AVAILABLE == _status) {
        std::cout << "Connection is [AVAILABLE] " << std::endl;
        initProxyCallback();

    } else {
        std::cout << "Connection is [NOT_AVAILABLE] " << std::endl;
    }
}
