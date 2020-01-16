#include "HelloProxyMain.h"
#include <CommonAPI/CommonAPI.hpp>
#include <iostream>
#include <string>
#include <unistd.h>

HelloProxyMain::HelloProxyMain()
    : mMyProxy(nullptr)
{
}

void HelloProxyMain::Init()
{
    std::string domain = "local";
    std::string instance = "commonapi.examples.HelloWorld";
    std::string connection = "client-sample";
    mMyProxy = CommonAPI::Runtime::get()->buildProxy<v0::commonapi::examples::HelloWorldProxy>(domain, instance, connection);

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
    }
}

void HelloProxyMain::callbackConnectionStatusChanged(CommonAPI::AvailabilityStatus _status)
{
    if (CommonAPI::AvailabilityStatus::AVAILABLE == _status) {
        std::cout << "proxy status : Available!\n";

        const std::string name = "World";
        CommonAPI::CallStatus callStatus;
        std::string returnMessage;

        mMyProxy->sayHello(name, callStatus, returnMessage);
        if (callStatus != CommonAPI::CallStatus::SUCCESS) {
            std::cerr << "Remote call failed!\n";
            return;
        }
        std::cout << "Got message: ’" << returnMessage << "’\n";
    } else {
        std::cout << "proxy status : Not available!\n";
    }
}
