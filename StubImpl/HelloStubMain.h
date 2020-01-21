#ifndef HELLOIMPL_H
#define HELLOIMPL_H

#include "HelloStubImpl.h"
#include <CommonAPI/CommonAPI.hpp>

class HelloStubMain {
public:
    HelloStubMain();

    static int dltInjCBUpdateXAttr(uint32_t service_id, void* data, uint32_t length);
    void Init();

private:
    static std::shared_ptr<HelloStubImpl> mMyService;
};

#endif // HELLOIMPL_H
