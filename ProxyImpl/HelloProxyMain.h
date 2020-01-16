#ifndef HELLOIMPL_H
#define HELLOIMPL_H

#include <v0/commonapi/examples/HelloWorldProxy.hpp>

class HelloProxyMain {
public:
    HelloProxyMain();
    void Init();
    void InitAsync();

    void callbackConnectionStatusChanged(CommonAPI::AvailabilityStatus _status);

private:
    std::shared_ptr<v0::commonapi::examples::HelloWorldProxyDefault> mMyProxy;
};

#endif // HELLOIMPL_H
