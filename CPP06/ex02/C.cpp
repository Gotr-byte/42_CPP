#include "C.hpp"


C::C(): Base(){
    std::cout << "generated C\n";
}
C::~C(){}
C::C(C& other): Base()
{
    (void)&other;
}
C &C::operator=(const C& other){
    (void)&other;
    return (*this);
}