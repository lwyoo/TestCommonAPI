/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v202001100728.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_PROJ_TESTCODE_Test_Code_PROXY_BASE_HPP_
#define V1_PROJ_TESTCODE_Test_Code_PROXY_BASE_HPP_

#include <v1/proj/testcode/TestCode.hpp>



#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <cstdint>
#include <vector>

#include <CommonAPI/Attribute.hpp>
#include <CommonAPI/Proxy.hpp>
#include <functional>
#include <future>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace proj {
namespace testcode {

class TestCodeProxyBase
    : virtual public CommonAPI::Proxy {
public:
    typedef CommonAPI::ObservableReadonlyAttribute< ::v1::proj::testcode::TestCode::SpeedType> SpeedTypeAttribute;
    typedef CommonAPI::ObservableReadonlyAttribute< int32_t> SpeedValueAttribute;

    typedef std::function<void(const CommonAPI::CallStatus&)> SetSpeedTypeAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, const TestCode::SpeedType&)> GetSpeedTypeAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&)> SetSpeedValueAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, const int32_t&)> GetSpeedValueAsyncCallback;

    virtual SpeedTypeAttribute& getSpeedTypeAttribute() = 0;
    virtual SpeedValueAttribute& getSpeedValueAttribute() = 0;


    virtual void setSpeedType(const TestCode::SpeedType &_type, CommonAPI::CallStatus &_internalCallStatus, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> setSpeedTypeAsync(const TestCode::SpeedType &_type, SetSpeedTypeAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual void getSpeedType(CommonAPI::CallStatus &_internalCallStatus, TestCode::SpeedType &_show, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> getSpeedTypeAsync(GetSpeedTypeAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual void setSpeedValue(const int32_t &_show, CommonAPI::CallStatus &_internalCallStatus, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> setSpeedValueAsync(const int32_t &_show, SetSpeedValueAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual void getSpeedValue(CommonAPI::CallStatus &_internalCallStatus, int32_t &_show, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> getSpeedValueAsync(GetSpeedValueAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
};

} // namespace testcode
} // namespace proj
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_PROJ_TESTCODE_Test_Code_PROXY_BASE_HPP_