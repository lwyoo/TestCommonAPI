#include "HelloStubMain.h"
#include <QtDebug>
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

    bool bRegisterService = runtime->registerService(domain, instance, mMyService, connection);

    if (true == bRegisterService) {
        //fire MyStatus OK
        qDebug() << Q_FUNC_INFO << "Register Service [Connected]";
        CommonTypes::EnumMyStatus status(CommonTypes::EnumMyStatus::ENUM_STATUS_OK);
        mMyService->fireMyStatusEventCB(status);
    } else {
        qDebug() << Q_FUNC_INFO << "Register Service [DisConnected]";
        //fire MyStatus Fail
        CommonTypes::EnumMyStatus status(CommonTypes::EnumMyStatus::ENUM_STATUS_FAIL);
        mMyService->fireMyStatusEventCB(status);
    }
}

void HelloStubMain::triggerEvent(int value)
{
}

void HelloStubMain::testFunction(int value)
{
    mMyService->fireMyEventEvent(value);
    qDebug() << Q_FUNC_INFO << "value : " << value;
}
