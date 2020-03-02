#ifndef HELLOIMPL_H
#define HELLOIMPL_H

#include <v0/commonapi/examples/HelloWorldProxy.hpp>

using CommonTypes = v0::commonapi::examples::CommonTypes;
class HelloProxyMain {
public:
    HelloProxyMain();
    void Init();
    void InitAsync();

    void callbackConnectionStatusChanged(CommonAPI::AvailabilityStatus _status);

    //attribute change callback
    void XValueChanged(const int32_t& x);
    void a1StructValueChanged(v0::commonapi::examples::CommonTypes::a1Struct a1);

    //fidl broadcast init
    bool SubscribeBroadcast();

private:
    //fidl attribute init
    bool SubscribeStubAttributeChagedEvent();
    void testAttributeValue();
    //fidl callback func
    void cbMyStatus(const CommonTypes::EnumMyStatus status);
    void callbackMyEventChanged(const int32_t& myValue);

private:
    std::shared_ptr<v0::commonapi::examples::HelloWorldProxyDefault> mMyProxy;
    int32_t mProxyX;
};

#endif // HELLOIMPL_H

//#include "v1/proj/dcluster/McuManager/McuManagerProxy.hpp"
//using MCUManagerType = v1::proj::dcluster::McuManager::McuManagerTypes;
//    void callbackAdasInfoAttributeChanged( const MCUManagerType::StAdasInfo &_value );
