#include <iostream>
#include "Fixed.hpp"

//int main( void ) {
//    Fixed a(11.0f);
//    Fixed b(-15.2f);
//    Fixed c(30.0f);
//    Fixed d(30.0f);
//    const Fixed Ca(-45.0f);
//    const Fixed Cb(30.0f);
//
//    std::cout << "a: " << a << " b: " << b <<std::endl;
//    if (a > b)
//        std::cout << "work";
//    if (b > a)
//        std::cout << "no";
//    if (a < b)
//        std::cout << "no";
//    if (b < a)
//        std::cout << "work";
//    if (a >= b)
//        std::cout << "work";
//    if (b >= a)
//        std::cout << "no";
//    if (c >= d)
//        std::cout << "work";
//    if (c == d)
//        std::cout << "work";
//    if (a == b)
//        std::cout << "no";
//    if ((a + b) == (b + a))
//        std::cout << "work";
//    else
//        std::cout << "no";
//    std::cout << std::endl;
//    std::cout << "a + b = " << a + b << std::endl;
//    std::cout << "a - b = " << a - b << std::endl;
//    std::cout << "a * b = " << a * b << std::endl;
//    std::cout << "a / b = " << a / b << std::endl;
//    std::cout << "min(a,b): " <<Fixed::min(a,b) << std::endl;
//    std::cout << "max(a,b): " <<Fixed::max(a,b) << std::endl;
//    std::cout << "min(a,b): " <<Fixed::constMin(Ca,Cb) << std::endl;
//    ++a;
//    ++a;
//    std::cout << "++a " << a <<std::endl;
//    return 0;
//}

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.09f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}