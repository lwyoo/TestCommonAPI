#ifndef HELLOIMPL_H
#define HELLOIMPL_H

#include "HelloStubImpl.h"
#include <CommonAPI/CommonAPI.hpp>

class HelloStubMain {
public:
    HelloStubMain();
    void Init();

private:
    std::shared_ptr<HelloStubImpl> mMyService;
};

#endif // HELLOIMPL_H
