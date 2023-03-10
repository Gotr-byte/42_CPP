#pragma once
#include <iostream>
#include <ostream>

class Fixed{
public:
    Fixed();
    Fixed(const Fixed &oldObj);
    ~Fixed();
    Fixed & operator = (const Fixed &oldObj);
    Fixed(const int inVal);
    Fixed(const float inVal);

    int     getRawBits(void)const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
private:
    int fixedNumVal;
    static const int bitsNum = 8;
};

 std::ostream & operator<<(std::ostream & o, Fixed const &fixed);