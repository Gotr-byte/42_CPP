#include "Animal.hpp"

Animal::Animal():_type("Animal"){
    std::cout << _type <<" is constructed" << std::endl;
}
Animal::Animal(const Animal &other){
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "Copy " << _type << " has been constructed" << std::endl;
}
Animal::~Animal(){
    std::cout << _type << " destructor called" << std::endl;
}
Animal & Animal::operator = (const Animal &other){

    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

void Animal::makeSound()const{
    std::cout << "Makes generic " << _type << " sounds" << std::endl;
}

std::string Animal::getType()const{return(_type);}

