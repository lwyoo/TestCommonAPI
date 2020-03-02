#include "CommonAPIStub.h"
#include <QDebug>

CommonAPIStub::CommonAPIStub()
    : mStubImpl(nullptr)
{
}

void CommonAPIStub::Init()
{
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::string domain = "local";
    std::string instance = "commonapi.examples.HelloWorld";
    std::string connection = "service-sample";

    mStubImpl = std::make_shared<CommonAPIStubImpl>();

    bool bRegisterService = runtime->registerService(domain, instance, mStubImpl, connection);

    if (true == bRegisterService) {
        //fire MyStatus OK
        qDebug() << Q_FUNC_INFO << "Register Service [Connected]";
        //        CommonTypes::EnumMyStatus status(CommonTypes::EnumMyStatus::ENUM_STATUS_OK);
        //        mStubImpl->fireMyStatusEventCB(status);
    } else {
        qDebug() << Q_FUNC_INFO << "Register Service [DisConnected]";
        //fire MyStatus Fail
        //        CommonTypes::EnumMyStatus status(CommonTypes::EnumMyStatus::ENUM_STATUS_FAIL);
        //        mStubImpl->fireMyStatusEventCB(status);
    }
}

void CommonAPIStub::testFunction(int value)
{
    mStubImpl->updateAdasInfo(value);
}
