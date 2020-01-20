#ifndef HELLOSTUBIMPL_H
#define HELLOSTUBIMPL_H
#include "v0/commonapi/examples/HelloWorldStubDefault.hpp"
#include <CommonAPI/CommonAPI.hpp>

class HelloStubImpl : public virtual v0::commonapi::examples::HelloWorldStubDefault {
public:
    HelloStubImpl();

    //fidl method
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHelloReply_t _reply) override;
};

#endif // HELLOSTUBIMPL_H
