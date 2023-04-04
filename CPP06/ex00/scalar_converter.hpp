#include <iostream>

class ScalarConverter
{
    public:
        // ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter & operator = (const ScalarConverter &other);
        static ScalarConverter createInstance(); {
            return ScalarConverter();
        }
        static void         convert(std::string literals);
        static bool         isDouble (const std::string &str);
        static bool         isFloat (const std::string &str);
        static bool         isInteger(const std::string& str)
    private:
        ScalarConverter();

};