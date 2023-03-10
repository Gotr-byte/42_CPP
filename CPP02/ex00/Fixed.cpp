#include "Fixed.hpp"
#include <iostream>


Fixed::Fixed():fixedNumVal(0){std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const Fixed &oldObj){
    setRawBits(oldObj.getRawBits());
    std::cout << "Copy constructor called" << std::endl;}

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}

Fixed &Fixed::operator = (const Fixed &oldObj){
    setRawBits(oldObj.getRawBits());
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

int     Fixed::getRawBits(void)const{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->fixedNumVal);
}

void    Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->fixedNumVal = raw;
}