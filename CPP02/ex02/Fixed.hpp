#pragma once
#include <iostream>
#include <ostream>
class Fixed{
public:
    Fixed();
    Fixed(const Fixed &oldObj);
    ~Fixed();
    Fixed & operator = (const Fixed &rightVal);
    Fixed(const int inVal);
    Fixed(const float inVal);
    bool    operator > (const Fixed  &rightVal);
    bool    operator < (const Fixed  &rightVal);
    bool    operator <= (const Fixed  &rightVal);
    bool    operator >= (const Fixed  &rightVal);
    bool    operator == (const Fixed  &rightVal);
    Fixed   operator + (const Fixed &rightVal);
    Fixed   operator - (const Fixed &rightVal);
    Fixed   operator * (const Fixed &rightVal);
    Fixed   operator / (const Fixed &rightVal);
    int     getRawBits(void)const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
private:
    int fixedNumVal;
    static const int bitsNum = 8;
};

 std::ostream & operator<<(std::ostream & o, Fixed const &fixed);