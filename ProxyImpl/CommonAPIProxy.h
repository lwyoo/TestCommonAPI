#ifndef COMMONAPIPROXY_H
#define COMMONAPIPROXY_H

#include "v1/proj/dcluster/McuManager/McuManagerProxy.hpp"
using MCUManagerType = v1::proj::dcluster::McuManager::McuManagerTypes;

class CommonAPIProxy {
public:
    CommonAPIProxy();
    void Init();
    void InitAsync();
    void callbackConnectionStatusChanged(CommonAPI::AvailabilityStatus _status);

    //fidl broadcast init
    bool SubscribeBroadcast();

private:
    //fidl attribute init
    bool SubscribeStubAttributeChagedEvent();

    //attribute change callback
    void callbackAdasInfoAttributeChanged(const MCUManagerType::StAdasInfo& _value);

    //debug
    void printAttributeValue();
    void printStAdasInfo(const MCUManagerType::StAdasInfo& _value);

private:
    std::shared_ptr<v1::proj::dcluster::McuManager::McuManagerProxyDefault> mCommonAPIProxy;
};

#endif // COMMONAPIPROXY_H
