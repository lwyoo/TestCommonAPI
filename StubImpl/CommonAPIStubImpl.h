#ifndef COMMONAPISTUBIMPL_H
#define COMMONAPISTUBIMPL_H

#include "v1/proj/dcluster/McuManager/McuManagerStubDefault.hpp"
#include <CommonAPI/CommonAPI.hpp>
#include <mutex>

using MCUManagerType = v1::proj::dcluster::McuManager::McuManagerTypes;

class CommonAPIStubImpl : public virtual v1::proj::dcluster::McuManager::McuManagerStubDefault {
public:
    CommonAPIStubImpl();

    void updateAdasInfo(int value);
};

#endif // COMMONAPISTUBIMPL_H
