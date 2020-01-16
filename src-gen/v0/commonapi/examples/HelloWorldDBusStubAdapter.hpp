/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.dbus 3.1.12.v201907221221.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V0_COMMONAPI_EXAMPLES_Hello_World_DBUS_STUB_ADAPTER_HPP_
#define V0_COMMONAPI_EXAMPLES_Hello_World_DBUS_STUB_ADAPTER_HPP_

#include <v0/commonapi/examples/HelloWorldStub.hpp>
#include "v0/commonapi/examples/HelloWorldDBusDeployment.hpp"

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/DBus/DBusAddressTranslator.hpp>
#include <CommonAPI/DBus/DBusFactory.hpp>
#include <CommonAPI/DBus/DBusStubAdapterHelper.hpp>
#include <CommonAPI/DBus/DBusStubAdapter.hpp>
#include <CommonAPI/DBus/DBusDeployment.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v0 {
namespace commonapi {
namespace examples {

template <typename _Stub = ::v0::commonapi::examples::HelloWorldStub, typename... _Stubs>
class HelloWorldDBusStubAdapterInternal
    : public virtual HelloWorldStubAdapter,
      public CommonAPI::DBus::DBusStubAdapterHelper< _Stub, _Stubs...>
     {
public:
    typedef CommonAPI::DBus::DBusStubAdapterHelper< _Stub, _Stubs...> HelloWorldDBusStubAdapterHelper;

    ~HelloWorldDBusStubAdapterInternal() {
        deactivateManagedInstances();
        HelloWorldDBusStubAdapterHelper::deinit();
    }

    virtual bool hasFreedesktopProperties() {
        return false;
    }

    inline static const char* getInterface() {
        return HelloWorld::getInterface();
    }

    void deactivateManagedInstances() {
    }

    static CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        ::v0::commonapi::examples::HelloWorldStub,
        CommonAPI::Version
        > getHelloWorldInterfaceVersionStubDispatcher;

    
    static CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
        ::v0::commonapi::examples::HelloWorldStub,
        std::tuple< std::string>,
        std::tuple< std::string>,
        std::tuple< CommonAPI::DBus::StringDeployment>,
        std::tuple< CommonAPI::DBus::StringDeployment>
    
        > sayHelloStubDispatcher;

    HelloWorldDBusStubAdapterInternal(
        const CommonAPI::DBus::DBusAddress &_address,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
        const std::shared_ptr<_Stub> &_stub)
    : CommonAPI::DBus::DBusStubAdapter(_address, _connection,false),
      HelloWorldDBusStubAdapterHelper(_address, _connection, false, _stub) {
        HelloWorldDBusStubAdapterHelper::addStubDispatcher({ "sayHello", "s" }, &sayHelloStubDispatcher);
        HelloWorldDBusStubAdapterHelper::addStubDispatcher({ "getInterfaceVersion", "" }, &getHelloWorldInterfaceVersionStubDispatcher);
    }

protected:
    virtual const char* getMethodsDBusIntrospectionXmlData() const {
        static const std::string introspectionData =
            "<method name=\"getInterfaceVersion\">\n"
                "<arg name=\"value\" type=\"uu\" direction=\"out\" />"
            "</method>\n"
            "<method name=\"sayHello\">\n"
            "<arg name=\"_name\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"_message\" type=\"s\" direction=\"out\" />\n"
            "</method>\n"
            ;
        return introspectionData.c_str();
    }

private:
};


template <typename _Stub, typename... _Stubs>
CommonAPI::DBus::DBusGetAttributeStubDispatcher<
    ::v0::commonapi::examples::HelloWorldStub,
    CommonAPI::Version
    > HelloWorldDBusStubAdapterInternal<_Stub, _Stubs...>::getHelloWorldInterfaceVersionStubDispatcher(&HelloWorldStub::lockInterfaceVersionAttribute, &HelloWorldStub::getInterfaceVersion, "uu");


template <typename _Stub, typename... _Stubs>
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    ::v0::commonapi::examples::HelloWorldStub,
    std::tuple< std::string>,
    std::tuple< std::string>,
    std::tuple< CommonAPI::DBus::StringDeployment>,
    std::tuple< CommonAPI::DBus::StringDeployment>

    > HelloWorldDBusStubAdapterInternal<_Stub, _Stubs...>::sayHelloStubDispatcher(
    &HelloWorldStub::sayHello, "s",
    std::make_tuple(static_cast< CommonAPI::DBus::StringDeployment* >(nullptr)),
    std::make_tuple(static_cast< CommonAPI::DBus::StringDeployment* >(nullptr)));


template <typename _Stub = ::v0::commonapi::examples::HelloWorldStub, typename... _Stubs>
class HelloWorldDBusStubAdapter
    : public HelloWorldDBusStubAdapterInternal<_Stub, _Stubs...>,
      public std::enable_shared_from_this< HelloWorldDBusStubAdapter<_Stub, _Stubs...>> {
public:
    HelloWorldDBusStubAdapter(
        const CommonAPI::DBus::DBusAddress &_address,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection> &_connection,
        const std::shared_ptr<_Stub> &_stub)
        : CommonAPI::DBus::DBusStubAdapter(
            _address,
            _connection,
            false),
          HelloWorldDBusStubAdapterInternal<_Stub, _Stubs...>(
            _address,
            _connection,
            _stub) {
    }
};

} // namespace examples
} // namespace commonapi
} // namespace v0

#endif // V0_COMMONAPI_EXAMPLES_Hello_World_DBUS_STUB_ADAPTER_HPP_