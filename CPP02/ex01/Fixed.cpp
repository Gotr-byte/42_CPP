#include "Fixed.hpp"

Fixed::Fixed():fixedNumVal(0){std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const int inVal): fixedNumVal(inVal * (1 << bitsNum)){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float inValFloat): fixedNumVal((inValFloat * (1 << bitsNum)) + (inValFloat >= 0 ? 0.5 : -0.5)){
    std::cout << "Float constructor called" << std::endl;
}
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
//    std::cout << "getRawBits member function called" << std::endl;
    return(this->fixedNumVal);
}

void    Fixed::setRawBits(int const raw){
//    std::cout << "setRawBits member function called" << std::endl;
    this->fixedNumVal = raw;
}

float   Fixed::toFloat() const {
        return (float)(getRawBits()) / float(1 << bitsNum);
}

int     Fixed::toInt() const {
        return int(getRawBits() / int(1 << bitsNum));
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed){
    o << fixed.toFloat();
    return o;
}