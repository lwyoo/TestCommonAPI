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

    //    QDebug(QtMsgType::QtDebugMsg) << Q_FUNC_INFO << "current xAttr Value : " << mMyService->getXAttribute();
    //    mMyService->setXAttribute(7);
    //    QDebug(QtMsgType::QtDebugMsg) << Q_FUNC_INFO << "x value changed frome stub, xAttr Value : " << mMyService->getXAttribute();

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

void HelloStubMain::testFunction(int value)
{
    //    qDebug() << Q_FUNC_INFO << 1;
    //    CommonTypes::EnumMyStatus status(CommonTypes::EnumMyStatus::ENUM_STATUS_OK);
    //    qDebug() << Q_FUNC_INFO << 2;
    //    if (mMyService != nullptr) {
    //        qDebug() << Q_FUNC_INFO << 3;
    //        mMyService->fireMyStatusEventCB(status);
    //    } else {
    //        qDebug() << Q_FUNC_INFO << "errer";
    //    }

    mMyService->fireMyEventEvent(value);
    qDebug() << Q_FUNC_INFO << "value : " << value;
}
