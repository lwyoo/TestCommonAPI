#include "HelloStubImpl.h"
#include <QtDebug>
#include <iostream>
#include <string>

void HelloStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::__cxx11::string _name, v0::commonapi::examples::HelloWorldStub::sayHelloReply_t _reply)
{
    std::stringstream messageStream;
    messageStream << "Hello " << _name << "!";
    std::this_thread::sleep_for(std::chrono::seconds(8));
    std::cout << "sayHello(’" << _name << "’): ’" << messageStream.str() << "’\n";
    //    setXAttribute(5);
    _reply(messageStream.str());
}

void HelloStubImpl::fireMyStatusEventCB(v0::commonapi::examples::CommonTypes::EnumMyStatus& _status)
{
    QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << " called!";
    if (false == _status.validate()) {
        QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << " input value err!";
        return;
    }

    _status = CommonTypes::EnumMyStatus::ENUM_STATUS_OK;
    HelloWorldStubDefault::fireMyStatusEvent(_status);
}

void HelloStubImpl::fireMyEventEvent(const int32_t& _myValue)
{
    QDebug(QtMsgType::QtInfoMsg) << Q_FUNC_INFO << " called!";

    HelloWorldStubDefault::fireMyEventEvent(_myValue);
}
