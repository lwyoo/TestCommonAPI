/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v202001100728.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_PROJ_TESTCODE_TEST_CODE_HPP_
#define V1_PROJ_TESTCODE_TEST_CODE_HPP_




#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <CommonAPI/Types.hpp>
#include <cstdint>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace proj {
namespace testcode {

class TestCode {
public:
    virtual ~TestCode() { }

    static inline const char* getInterface();
    static inline CommonAPI::Version getInterfaceVersion();
    
    struct SpeedType : CommonAPI::Enumeration< int32_t> {
        enum Literal : int32_t {
            SPEED_KIL = 0,
            SPEED_MILE = 1,
            MAX = 2
        };
    
        SpeedType()
            : CommonAPI::Enumeration< int32_t>(static_cast< int32_t>(Literal::SPEED_KIL)) {}
        SpeedType(Literal _literal)
            : CommonAPI::Enumeration< int32_t>(static_cast< int32_t>(_literal)) {}
    
        inline bool validate() const {
            switch (value_) {
                case static_cast< int32_t>(Literal::SPEED_KIL):
                case static_cast< int32_t>(Literal::SPEED_MILE):
                case static_cast< int32_t>(Literal::MAX):
                return true;
            default:
                return false;
            }
        }
    
        inline bool operator==(const SpeedType &_other) const { return (value_ == _other.value_); }
        inline bool operator!=(const SpeedType &_other) const { return (value_ != _other.value_); }
        inline bool operator<=(const SpeedType &_other) const { return (value_ <= _other.value_); }
        inline bool operator>=(const SpeedType &_other) const { return (value_ >= _other.value_); }
        inline bool operator<(const SpeedType &_other) const { return (value_ < _other.value_); }
        inline bool operator>(const SpeedType &_other) const { return (value_ > _other.value_); }
    
        inline bool operator==(const Literal &_value) const { return (value_ == static_cast< int32_t>(_value)); }
        inline bool operator!=(const Literal &_value) const { return (value_ != static_cast< int32_t>(_value)); }
        inline bool operator<=(const Literal &_value) const { return (value_ <= static_cast< int32_t>(_value)); }
        inline bool operator>=(const Literal &_value) const { return (value_ >= static_cast< int32_t>(_value)); }
        inline bool operator<(const Literal &_value) const { return (value_ < static_cast< int32_t>(_value)); }
        inline bool operator>(const Literal &_value) const { return (value_ > static_cast< int32_t>(_value)); }
    };
};

const char* TestCode::getInterface() {
    return ("proj.testcode.TestCode:v1_0");
}

CommonAPI::Version TestCode::getInterfaceVersion() {
    return CommonAPI::Version(1, 0);
}


} // namespace testcode
} // namespace proj
} // namespace v1

namespace CommonAPI {
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_PROJ_TESTCODE_TEST_CODE_HPP_
