#pragma once
#include <iostream>
#include <stack>
#include <ctype.h>

class RPN
{
    public:
        RPN();
        ~RPN();
        std::stack<int> digits;
        int first_operand;
        int second_operand;
        int i;
    private:
        RPN(const RPN &other);
        RPN & operator = (const RPN &other);
};
