#pragma once
#include <iostream>

class ScalarConverter
{
    public:
        static void         convert(std::string literals);
        static bool         isDouble (const std::string &str);
        static bool         isFloat (const std::string &str);
        static bool         isInteger(const std::string& str);
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter & operator = (const ScalarConverter &other);
        ~ScalarConverter();
};