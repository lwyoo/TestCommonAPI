#include "HelloStubImpl.h"
#include <iostream>
#include <string>

void HelloStubImpl::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::__cxx11::string _name, v0::commonapi::examples::HelloWorldStub::sayHelloReply_t _reply)
{
    std::stringstream messageStream;
    messageStream << "Hello " << _name << "!";
    std::cout << "sayHello(’" << _name << "’): ’" << messageStream.str() << "’\n";
    _reply(messageStream.str());
}
