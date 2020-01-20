#ifndef HELLOIMPL_H
#define HELLOIMPL_H

#include <v0/commonapi/examples/HelloWorldProxy.hpp>

class HelloProxyMain {
public:
    HelloProxyMain();
    void Init();
    void InitAsync();

    void callbackConnectionStatusChanged(CommonAPI::AvailabilityStatus _status);

    //attribute change callback
    void XValueChanged(const int32_t& x);
    void a1StructValueChanged(v0::commonapi::examples::CommonTypes::a1Struct a1);

private:
    bool SubscribeStubAttributeChagedEvent();
    void testAttributeValue();

private:
    std::shared_ptr<v0::commonapi::examples::HelloWorldProxyDefault> mMyProxy;
    int32_t mProxyX;
};

#endif // HELLOIMPL_H
