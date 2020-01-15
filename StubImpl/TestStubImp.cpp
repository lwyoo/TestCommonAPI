#include "TestStubImp.h"

#include <iostream>
TestStubImp::TestStubImp()
{
}

void TestStubImp::Init()
{

    CommonAPI::Runtime::get()->registerService("local",
        "proj.testCode",
        mTestStub);
}
