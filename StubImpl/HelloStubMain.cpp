#include "HelloStubMain.h"
#include <thread>

HelloStubMain::HelloStubMain()
    : mMyService(nullptr)
{
}

void HelloStubMain::Init()
{
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::string domain = "local";
    std::string instance = "commonapi.examples.HelloWorld";
    std::string connection = "service-sample";

    mMyService = std::make_shared<HelloStubImpl>();

    runtime->registerService(domain, instance, mMyService, connection);
}
