#include "Animal.hpp"


Animal::Animal():_type("Animal"){
    std::cout << _type <<" is constructed" << std::endl;
}
Animal::Animal(const Animal &other){
    if (this != &other) {
        *this = other;
    }
    std::cout << "Copy Animal constructor has been called" << std::endl;
}
Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}
Animal & Animal::operator = (const Animal &other){
    this->_type = other._type;
    return *this;
}

void Animal::makeSound()const{
    std::cout << "Makes generic Animal sounds" << std::endl;
}

std::string Animal::getType() const {return(_type);}

