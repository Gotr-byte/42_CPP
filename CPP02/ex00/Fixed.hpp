#pragma once

class Fixed{
public:
    Fixed();
    Fixed(const Fixed &oldObj);
    ~Fixed();
    Fixed & operator = (const Fixed &oldObj);
    int     getRawBits(void)const;
    void    setRawBits(int const raw);
private:
    int fixedNumVal;
    static const int bitsNum = 8;

};