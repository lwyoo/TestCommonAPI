#include "HelloStubImpl.h"
#include <QtDebug>
#include <iostream>
#include <string>

HelloStubImpl::HelloStubImpl()
    : m_xAttributeValue_(0)
{
}

const int32_t& HelloStubImpl::getXAttribute()
{
    QDebug(QtMsgType::QtDebugMsg) << Q_FUNC_INFO;
    const int32_t locX = HelloWorldStubDefault::getXAttribute();
    if (m_xAttributeValue_ == locX) {
        std::cout << "Parent and child x value is same! [" << m_xAttributeValue_ << "] returned!" << std::endl;
        return m_xAttributeValue_;
    } else {
        std::cout << "Parent and child x value is different! return parent(stubDefault) value. [" << HelloWorldStubDefault::getXAttribute()
                  << "] returned!" << std::endl;
        return HelloWorldStubDefault::getXAttribute();
    }
}

const int32_t& HelloStubImpl::getXAttribute(const std::shared_ptr<CommonAPI::ClientId> _client)
{
    QDebug(QtMsgType::QtDebugMsg) << Q_FUNC_INFO;
    std::cout << "Client ID : " << _client->hashCode() << std::endl;
    return HelloWorldStubDefault::getXAttribute(_client);
}

//void HelloStubImpl::setXAttribute(int32_t _value)
//{
//    QDebug(QtMsgType::QtDebugMsg) << Q_FUNC_INFO << "requsted setting value = " << _value;
//    m_xAttributeValue_ = _value;
//    HelloWorldStubDefault::setXAttribute(_value);
//}

//void HelloStubImpl::setXAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _value)
//{
//    QDebug(QtMsgType::QtDebugMsg) << Q_FUNC_INFO << "requsted setting value = " << _value;
//    m_xAttributeValue_ = _value;
//    HelloWorldStubDefault::setXAttribute(_client, _value);
//}

void HelloStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::__cxx11::string _name, v0::commonapi::examples::HelloWorldStub::sayHelloReply_t _reply)
{
    std::stringstream messageStream;
    messageStream << "Hello " << _name << "!";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "sayHello(’" << _name << "’): ’" << messageStream.str() << "’\n";
    //    setXAttribute(5);
    _reply(messageStream.str());
}
