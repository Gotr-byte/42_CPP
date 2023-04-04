#include "scalar_converter.hpp"
#include "ctype.h"
#include "stdlib.h"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &other){
    (void)&other;
}
ScalarConverter & ScalarConverter::operator = (const ScalarConverter &other){
    (void)&other;
    return (*this);
}

ScalarConverter ScalarConverter::createInstance(){
            return ScalarConverter();
        }

bool ScalarConverter::isInteger(const std::string& str) {
    if (str.empty() || (!isdigit(str[0]) && str[0] != '-' && str[0] != '+')) {
        return false;
    }
    for (std::string::size_type i = 1; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    if (str.size() > 10) {
        std::cerr << "Out of bounds error\n";
        return false;
    }
    int value = atoi(str.c_str());
    return value != 0 || (str[0] == '0' && str.size() == 1 
    && std::numeric_limits<int>::min() <= value &&
    value <= std::numeric_limits<int>::max());
}

bool ScalarConverter::isFloat (const std::string &str)
{
    bool isInt = 1;
    if (str.empty())
    {
        isInt = 0;
    }
    std::string minus = "-";
    std::string plus = "+";
    std::string::size_type pos = 0;
    if (str[pos] == '-'|| str[pos] == '+')
        pos++;
    while (isdigit(str[pos]))
        pos++;
    if (!(str[pos] == '.'))
        isInt = 0;
    if (str[pos] == '.')
        pos++;
    while (isdigit(str[pos]))
        pos++;
    if (str[pos] == 'f')
        pos++;
    else
        isInt = 0;
    if(pos != str.size())
        isInt = 0;
    return isInt;
}

bool ScalarConverter::isDouble (const std::string &str)
{
    bool isDouble = 1;
    if (str.empty())
        isDouble = 0;
    std::string minus = "-";
    std::string plus = "+";
    std::string::size_type pos = 0;
    if (str[pos] == '-'|| str[pos] == '+')
        pos++;
    while (isdigit(str[pos]))
        pos++;
    if (!(str[pos] == '.'))
        isDouble = 0;
    if (str[pos] == '.')
        pos++;
    while (isdigit(str[pos]))
        pos++;
    if(pos != str.size())
        isDouble = 0;
    return isDouble;
}

void ScalarConverter::convert(std::string literals){
    if (literals == "nanf" || literals == "nan")
    {
        std::cout << "char value: " << "out of char bound\n";
        std::cout << "int value: " << "nan is not implemented in int" << "\n";
        std::cout << "float value: " << "nanf" <<"\n";
        std::cout << "double value: " << "nan" <<"\n";
    }
    else if (literals == "-inff" || literals == "-inf")
    {
        std::cout << "char value: " << "out of char bound\n";
        std::cout << "int value: " << "-2147483648" << "\n";
        std::cout << "float value: " << "-inff" <<"\n";
        std::cout << "double value: " << "-inf" <<"\n";
    }
    else if (literals == "inff" || literals == "inf")
    {
        std::cout << "char value: " << "out of char bound\n";
        std::cout << "int value: " << "2147483647" << "\n";
        std::cout << "float value: " << "inff" <<"\n";
        std::cout << "double value: " << "inf" <<"\n";
    }
    else if (literals.length() == 1 && literals[0] > ' ' &&
     literals[0] < '~' && !isdigit(literals[0]))
    {
        std::cout << "char value: " << literals[0] << "\n";
        std::cout << "int value: " << static_cast<int>(literals[0]) << "\n";
        std::cout << "float value: " << static_cast<float>(literals[0]) << ".0f" <<"\n";
        std::cout << "double value: " << static_cast<double>(literals[0]) << ".0" <<"\n";
    }
    else if (ScalarConverter::isInteger(literals))
    {
        int intValue = atoi(literals.c_str());
        if (intValue >= 0 && intValue < 32)
            std::cout << "char value: unprintable char \n";
        else if(intValue > 127 || intValue < 0)
            std::cout << "char value: out of char bounds\n";
        else
            std::cout << "char value: " << static_cast<char>(intValue) << "\n";
        std::cout << "int value: " << intValue << "\n";
        std::cout << "float value: " << static_cast<float>(intValue) << ".0f" <<"\n";
        std::cout << "double value: " << static_cast<double>(intValue) << ".0" <<"\n";
    }
    else if (ScalarConverter::isFloat(literals))
    {
        float floatValue = strtof(literals.c_str(), NULL);

        if (floatValue >= 0 && floatValue < 32)
            std::cout << "char value: unprintable char \n";
        else if((floatValue >= 127 || floatValue < 0))
            std::cout << "char value: out of char bounds\n";
        else
            std::cout << "char value: " << static_cast<char>(floatValue) << "\n";
        std::cout << "int value: " << static_cast<int>(floatValue) << "\n";
        if (fmod(floatValue, 1) == 0)
        {
            std::cout << "float value: " << floatValue << ".0f\n";
            std::cout << "double value: " << static_cast<double>(floatValue) <<".0\n";
        } 
        else 
        {
            std::cout << "float value: " << floatValue << "f\n";
            std::cout << "double value: " << static_cast<double>(floatValue) <<"\n";
        }
    }
    else if(ScalarConverter::isDouble(literals))
    {
        double doubleValue = strtod(literals.c_str(), NULL);
        if (doubleValue >= 0 && doubleValue < 32)
            std::cout << "char value: unprintable char \n";
        else if((doubleValue >= 127 || doubleValue < 0))
            std::cout << "char value: out of char bounds\n";
        else
            std::cout << "char value: " << static_cast<char>(doubleValue) << "\n";
         std::cout << "int value: " << static_cast<int>(doubleValue) << "\n";
         if (fmod(doubleValue, 1) == 0)
        {
            std::cout << "float value: " << static_cast<float>(doubleValue) << ".0f" <<"\n";
            std::cout << "double value: " << doubleValue <<".0\n";
        } 
        else 
        {
             std::cout << "float value: " << static_cast<float>(doubleValue) << "f" <<"\n";
            std::cout << "double value: " << doubleValue <<"\n";
        }
    }
    else
    {
        std::cout << "char value: " << "conversion not available\n";
        std::cout << "int value: " << "conversion not available\n";
        std::cout << "float value: " << "conversion not available\n";
        std::cout << "double value: " << "conversion not available\n";
    }
}
