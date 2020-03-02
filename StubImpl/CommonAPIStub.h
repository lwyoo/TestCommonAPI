#ifndef COMMONAPISTUB_H
#define COMMONAPISTUB_H

//#include "HelloStubImpl.h"
#include "CommonAPIStubImpl.h"
#include <CommonAPI/CommonAPI.hpp>

class CommonAPIStub {
public:
public:
    CommonAPIStub();
    void Init();
    void testFunction(int value);

private:
    std::shared_ptr<CommonAPIStubImpl> mStubImpl;
    int32_t mMyValue = 0;
};

#endif // COMMONAPISTUB_H
