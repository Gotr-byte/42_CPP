#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed():fixedNumVal(0){std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const int inVal): fixedNumVal(inVal * (1 << bitsNum)){
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float inValFloat): fixedNumVal(roundf(inValFloat * (1 << bitsNum))){
    std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &oldObj){
    setRawBits(oldObj.getRawBits());
    std::cout << "Copy constructor called" << std::endl;}

Fixed::~Fixed(){std::cout << "Destructor called" << std::endl;}

Fixed &Fixed::operator = (const Fixed &rightVal){
    setRawBits(rightVal.getRawBits());
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

bool    Fixed::operator > (const Fixed  &rightVal)
{
    return (this->fixedNumVal > rightVal.getRawBits() ? true : false);
}

bool    Fixed::operator < (const Fixed  &rightVal)
{
    return (this->fixedNumVal < rightVal.getRawBits() ? true : false);
}

bool    Fixed::operator <= (const Fixed  &rightVal)
{
    return (this->fixedNumVal <= rightVal.getRawBits() ? true : false);
}

bool    Fixed::operator >= (const Fixed  &rightVal)
{
    return (this->fixedNumVal >= rightVal.getRawBits() ? true : false);
}

bool    Fixed::operator == (const Fixed  &rightVal)
{
    return (this->fixedNumVal == rightVal.getRawBits() ? true : false);
}

bool Fixed::operator!=(Fixed const &ref)
{
    return (this->getRawBits() != ref.getRawBits());
}

Fixed   Fixed::operator + (const Fixed &rightVal){
    Fixed sum;
    sum.setRawBits(this->fixedNumVal + rightVal.getRawBits());
    return(sum);
}

Fixed   Fixed::operator - (const Fixed &rightVal){
    Fixed diff;
    diff.setRawBits(this->fixedNumVal - rightVal.getRawBits());
    return(diff);
}

Fixed   Fixed::operator * (const Fixed &rightVal){
    return( this->toFloat() * rightVal.toFloat());
}

//Can trade range for precision here when changing the bitshift from the divided to the divisor
Fixed   Fixed::operator / (const Fixed &rightVal){
    Fixed sum;
    sum.setRawBits((this->fixedNumVal << this->bitsNum) / (rightVal.getRawBits()));
    return(sum);
}

Fixed &Fixed::operator++(){
    ++this->fixedNumVal;
    return(*this);
}

Fixed &Fixed::operator--(){
    --this->fixedNumVal;
    return(*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed cpy = *this;
    this->fixedNumVal++;
    return cpy;
}

Fixed   Fixed::operator--(int)
{
    Fixed cpy = *this;
    this->fixedNumVal--;
    return cpy;
}

Fixed &Fixed::min(Fixed &firstVal, Fixed &secondVal){
    return(firstVal > secondVal ? secondVal : firstVal);
}

Fixed &Fixed::max(Fixed &firstVal, Fixed &secondVal){
    return(firstVal > secondVal ? firstVal : secondVal);
}

Fixed const &Fixed::min(const Fixed &firstVal, const Fixed &secondVal) {
    return(firstVal.toFloat() > secondVal.toFloat() ? secondVal : firstVal);
}

Fixed const &Fixed::max(const Fixed &firstVal, const Fixed &secondVal){
    return(firstVal.toFloat() > secondVal.toFloat() ? firstVal : secondVal);
}
