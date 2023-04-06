#pragma once
#include "Base.hpp"
#include <iostream>

class B: public Base
{
    public:
        B();
        ~B();
        B(B& other);
        B &operator=(const B& other);
};