#include "HelloStubImpl.h"
#include <QtDebug>
#include <iostream>
#include <string>

HelloStubImpl::HelloStubImpl()
{
}

void HelloStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::__cxx11::string _name, v0::commonapi::examples::HelloWorldStub::sayHelloReply_t _reply)
{
    std::stringstream messageStream;
    messageStream << "Hello " << _name << "!";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "sayHello(’" << _name << "’): ’" << messageStream.str() << "’\n";
    //    setXAttribute(5);
    _reply(messageStream.str());
}
