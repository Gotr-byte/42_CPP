#include "Data.hpp"

Data::Data(): _x(11), _y(1){}
Data::~Data(){}
Data::Data(Data& other): _x(other.getX()), _y(other.getY()){
}
Data& Data::operator = (Data& other){
    if(this != &other)
    {
        this->_x = other.getX();
        this->_y = other.getY();
    }
    return *this;
}

int Data::getX ()
{
    return(this->_x);
}

double Data::getY ()
{
    return(this->_y);
}

void Data::setXy(int x, double y)
{
    this->_x = x;
    this->_y = y;
    std::cout << "set x value to: " << this->_x << "\n";
    std::cout << "set y value to: " << this->_y << "\n";
}

void Data::printValues()
{
    std::cout << "x value: " << this->getX() << std::endl;
    std::cout << "y value: " << this->getY() << std::endl;
}