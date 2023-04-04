#include "scalar_converter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "invalid number of arguments";
    }
    ScalarConverter::convert(argv[1]);
}