#ifndef TESTSTUBIMP_H
#define TESTSTUBIMP_H
#include "v1/proj/testcode/TestCodeStubDefault.hpp"
#include <CommonAPI/CommonAPI.hpp>

class TestStubImp : v1::proj::testcode::TestCodeStubDefault {
public:
    TestStubImp();
    void Init();

private:
    std::shared_ptr<v1::proj::testcode::TestCodeStubDefault> mTestStub = std::shared_ptr<v1::proj::testcode::TestCodeStubDefault>(new v1::proj::testcode::TestCodeStubDefault);
};

#endif // TESTSTUBIMP_H
