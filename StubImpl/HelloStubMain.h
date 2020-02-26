#ifndef HELLOIMPL_H
#define HELLOIMPL_H

#include "HelloStubImpl.h"
#include <CommonAPI/CommonAPI.hpp>

class HelloStubMain {
public:
    HelloStubMain();
    void Init();
    void testFunction(int value);

private:
    std::shared_ptr<HelloStubImpl> mMyService;
    int32_t mMyValue = 0;
};

#endif // HELLOIMPL_H
