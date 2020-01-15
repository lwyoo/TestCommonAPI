#ifndef TESTPROXYIMP_H
#define TESTPROXYIMP_H

#include "v1/proj/testcode/TestCodeProxy.hpp"

class TestProxyImp {
public:
    TestProxyImp();
    void Init();
    void setSpeedType(int speedType);
    int getSpeedType();

    void setSpeedValue(int speedValue);
    int getSpeedValue();
    void initProxyCallback();


    void callbackConnectionStatusChanged(CommonAPI::AvailabilityStatus _status);

private:
    std::shared_ptr<v1::proj::testcode::TestCodeProxy<>> mTestProxy;
};

#endif // TESTPROXYIMP_H
