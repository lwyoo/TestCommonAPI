/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v202001100728.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_PROJ_DCLUSTER_MCUMANAGER_MCU_MANAGER_HPP_
#define V1_PROJ_DCLUSTER_MCUMANAGER_MCU_MANAGER_HPP_




#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Types.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace proj {
namespace dcluster {
namespace McuManager {

class McuManager {
public:
    virtual ~McuManager() { }

    static inline const char* getInterface();
    static inline CommonAPI::Version getInterfaceVersion();
};

const char* McuManager::getInterface() {
    return ("proj.dcluster.McuManager.McuManager:v1_0");
}

CommonAPI::Version McuManager::getInterfaceVersion() {
    return CommonAPI::Version(1, 0);
}


} // namespace McuManager
} // namespace dcluster
} // namespace proj
} // namespace v1

namespace CommonAPI {
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_PROJ_DCLUSTER_MCUMANAGER_MCU_MANAGER_HPP_
