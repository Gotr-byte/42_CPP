#pragma once
#include "Base.hpp"
#include <iostream>

class A : public Base
{
     public:
        A();
        ~A();
        A(A& other);
        A &operator=(const A& other);
};