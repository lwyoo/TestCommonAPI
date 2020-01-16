/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201907221047.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <v0/commonapi/examples/HelloWorldStubDefault.hpp>
#include <assert.h>

namespace v0 {
namespace commonapi {
namespace examples {

HelloWorldStubDefault::HelloWorldStubDefault():
        remoteEventHandler_(this),
        interfaceVersion_(HelloWorld::getInterfaceVersion()) {
}

const CommonAPI::Version& HelloWorldStubDefault::getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) {
    (void)_client;
    return interfaceVersion_;
}

HelloWorldStubRemoteEvent* HelloWorldStubDefault::initStubAdapter(const std::shared_ptr< HelloWorldStubAdapter> &_adapter) {
    CommonAPI::Stub<HelloWorldStubAdapter, HelloWorldStubRemoteEvent>::stubAdapter_ = _adapter;
    return &remoteEventHandler_;
}


void HelloWorldStubDefault::sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHelloReply_t _reply) {
    (void)_client;
    (void)_name;
    std::string message = "";
    _reply(message);
}




HelloWorldStubDefault::RemoteEventHandler::RemoteEventHandler(HelloWorldStubDefault *_defaultStub)
    : 
      defaultStub_(_defaultStub) {
}

} // namespace examples
} // namespace commonapi
} // namespace v0
