#include "B.hpp"

B::B():Base(){
    std::cout << "generated B\n";
}
B::~B(){}
B::B(B& other):Base()
{
    (void)&other;
}
B &B::operator=(const B& other){
    (void)&other;
    return (*this);
}