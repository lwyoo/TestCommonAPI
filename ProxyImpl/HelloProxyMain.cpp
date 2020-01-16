#include "HelloProxyMain.h"
#include <CommonAPI/CommonAPI.hpp>
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

        const std::string name = "World";
        CommonAPI::CallStatus callStatus;
        std::string returnMessage;

        QElapsedTimer timer;
        timer.start();
        mMyProxy->sayHello(name, callStatus, returnMessage);
        double elapsedSec = static_cast<double>(timer.elapsed()) / 1000.;
        std::cout << "sayHello() sync called! Time : " << elapsedSec << " sec elapsed." << std::endl;

        if (callStatus != CommonAPI::CallStatus::SUCCESS) {
            std::cerr << "Remote call failed!\n";
            return;
        }
        std::cout << "Got message: ’" << returnMessage << "’\n";

        //aync call
        timer.restart();
        mMyProxy->sayHelloAsync("World Async", &sayHelloAsyncCallback);
        std::cout << "sayHello() async called! Time : " << timer.elapsed() << " milliseconds elapsed." << std::endl;
    } else {
        std::cout << "proxy status : Not available!\n";
    }
}
