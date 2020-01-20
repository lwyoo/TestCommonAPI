#ifndef HELLOSTUBIMPL_H
#define HELLOSTUBIMPL_H
#include "v0/commonapi/examples/HelloWorldStubDefault.hpp"
#include <CommonAPI/CommonAPI.hpp>

class HelloStubImpl : public virtual v0::commonapi::examples::HelloWorldStubDefault {
public:
    HelloStubImpl();
    //fidl attribute
    virtual const int32_t& getXAttribute() override;
    virtual const int32_t& getXAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) override;
    //    virtual void setXAttribute(int32_t _value) override;
    //    virtual void setXAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, int32_t _value) override;

    //fidl method
    virtual void sayHello(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _name, sayHelloReply_t _reply) override;

private:
    int32_t m_xAttributeValue_;
    //    ::v0::commonapi::examples::CommonTypes::a1Struct m_a1AttributeValue_;
};

#endif // HELLOSTUBIMPL_H
