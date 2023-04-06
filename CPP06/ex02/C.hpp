#pragma once
#include "Base.hpp"
#include <iostream>

class C: public Base
{
    public:
        C();
        ~C();
        C(C& other);
        C &operator=(const C& other);
};