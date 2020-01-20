#ifndef HELLOSTUBIMPL_H
#define HELLOSTUBIMPL_H
#include "v0/commonapi/examples/HelloWorldStubDefault.hpp"
#include <CommonAPI/CommonAPI.hpp>
#include <mutex>

using CommonTypes = v0::commonapi::examples::CommonTypes;

class HelloStubImpl : public virtual v0::commonapi::examples::HelloWorldStubDefault {
public:
    //fidl method
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHelloReply_t _reply) override;

    //fidl broadcast
    void fireMyStatusEventCB(v0::commonapi::examples::CommonTypes::EnumMyStatus& _status);
};

#endif // HELLOSTUBIMPL_H
