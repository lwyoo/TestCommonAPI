/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.1.12.v201907221221.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include <v1/proj/dcluster/McuManager/McuManager.hpp>
#include <v1/proj/dcluster/McuManager/McuManagerDBusStubAdapter.hpp>

namespace v1 {
namespace proj {
namespace dcluster {
namespace McuManager {

std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> createMcuManagerDBusStubAdapter(
                   const CommonAPI::DBus::DBusAddress &_address,
                   const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
                   const std::shared_ptr<CommonAPI::StubBase> &_stub) {
    return std::make_shared< McuManagerDBusStubAdapter<::v1::proj::dcluster::McuManager::McuManagerStub>>(_address, _connection, std::dynamic_pointer_cast<::v1::proj::dcluster::McuManager::McuManagerStub>(_stub));
}

void initializeMcuManagerDBusStubAdapter() {
    CommonAPI::DBus::Factory::get()->registerStubAdapterCreateMethod(
        McuManager::getInterface(), &createMcuManagerDBusStubAdapter);
}

INITIALIZER(registerMcuManagerDBusStubAdapter) {
    CommonAPI::DBus::Factory::get()->registerInterface(initializeMcuManagerDBusStubAdapter);
}

} // namespace McuManager
} // namespace dcluster
} // namespace proj
} // namespace v1
