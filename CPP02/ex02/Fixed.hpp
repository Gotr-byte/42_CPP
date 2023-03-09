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
    bool            operator > (const Fixed  &rightVal);
    bool            operator < (const Fixed  &rightVal);
    bool            operator <= (const Fixed  &rightVal);
    bool            operator >= (const Fixed  &rightVal);
    bool            operator == (const Fixed  &rightVal);
    bool            operator != (const Fixed &rightVal);
    Fixed           operator + (const Fixed &rightVal);
    Fixed           operator - (const Fixed &rightVal);
    Fixed           operator * (const Fixed &rightVal);
    Fixed           operator / (const Fixed &rightVal);
    Fixed&	        operator++();
    Fixed&	        operator--();
    Fixed           operator++(int);
    Fixed           operator--(int);
    static          Fixed  &min(Fixed &firstVal, Fixed &secondVal);
    static          Fixed  &max(Fixed &firstVal, Fixed &secondVal);
    static          const Fixed  &min(const Fixed &firstVal, const Fixed &secondVal);
    static          const Fixed  &max(const Fixed &firstVal, const Fixed &secondVal);
    int             getRawBits(void)const;
    void            setRawBits(int const raw);
    float           toFloat(void) const;
    int             toInt(void) const;
private:
    int fixedNumVal;
    static const int bitsNum = 8;
};

 std::ostream & operator<<(std::ostream & o, Fixed const &fixed);