#include "A.hpp"

A::A():Base(){
    std::cout << "generated A\n";
}
A::~A(){}
A::A(A& other):Base()
{
    (void)&other;
}
A &A::operator=(const A& other){
    (void)&other;
    return (*this);
}