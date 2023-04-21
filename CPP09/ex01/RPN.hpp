#pragma once
#include <iostream>
#include <stack>
#include <ctype.h>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        std::stack<int> digits;
        int first_operand;
        int second_operand;
        int i;
        int operator_number;
    private:
        RPN & operator = (const RPN &other);
};
