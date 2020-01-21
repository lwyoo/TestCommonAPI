#include "HelloStubMain.h"
#include <QtDebug>
#include <dlt/dlt.h>
#include <thread>

DLT_DECLARE_CONTEXT(ContextStub)

std::shared_ptr<HelloStubImpl> HelloStubMain::mMyService = std::make_shared<HelloStubImpl>();

HelloStubMain::HelloStubMain()
{
}

int HelloStubMain::dltInjCBUpdateXAttr(uint32_t service_id, void* data, uint32_t length)
{
    DLT_LOG(ContextStub, DLT_LOG_WARN, DLT_STRING("11111111111111111111111111111111111111111111111111111111111"));
    if (data == nullptr || length == 0) {
        DLT_LOG(ContextStub, DLT_LOG_WARN, DLT_STRING("Invalid Command"));

        return -1;
    }

    //    DLT_LOG(ContextStub, DLT_LOG_INFO, DLT_STRING("service id : "), DLT_UINT(service_id), DLT_STRING(" length : "), DLT_UINT(length));

    return 0;
}

void HelloStubMain::Init()
{
    DLT_REGISTER_APP("Stub", "stub application");
    DLT_REGISTER_CONTEXT(ContextStub, "sapp", "stub context");
    DLT_REGISTER_INJECTION_CALLBACK(ContextStub, 0xfff, &dltInjCBUpdateXAttr);
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::string domain = "local";
    std::string instance = "commonapi.examples.HelloWorld";
    std::string connection = "service-sample";

    //    mMyService = std::make_shared<HelloStubImpl>();

    bool bRegisterService = runtime->registerService(domain, instance, mMyService, connection);

    //    QDebug(QtMsgType::QtDebugMsg) << Q_FUNC_INFO << "current xAttr Value : " << mMyService->getXAttribute();
    //    mMyService->setXAttribute(7);
    //    QDebug(QtMsgType::QtDebugMsg) << Q_FUNC_INFO << "x value changed frome stub, xAttr Value : " << mMyService->getXAttribute();

    if (true == bRegisterService) {
        //fire MyStatus OK
        CommonTypes::EnumMyStatus status(CommonTypes::EnumMyStatus::ENUM_STATUS_OK);
        mMyService->fireMyStatusEventCB(status);
    } else {
        //fire MyStatus Fail
        CommonTypes::EnumMyStatus status(CommonTypes::EnumMyStatus::ENUM_STATUS_FAIL);
        mMyService->fireMyStatusEventCB(status);
    }
}
