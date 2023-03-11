#include "Dog.hpp"

Dog::Dog(): Animal(){
    this->_type = "Dog";
    std::cout << _type << " constructor has been called" << std::endl;
}
Dog::Dog(const Dog &other){
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "Copy << _type << has been constructed" << std::endl;
}
Dog::~Dog(){
    std::cout << _type <<" destructor called" << std::endl;
}
Dog & Dog::operator = (const Dog &other){

    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

void Dog::makeSound()const{
    std::cout << "Makes generic " << _type << " sounds" << std::endl;
}

//std::string Dog::getType(){return(this->_type);}