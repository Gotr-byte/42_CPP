#include "AAnimal.hpp"


AAnimal::AAnimal():_type("AAnimal"){
    std::cout << _type <<" is constructed" << std::endl;
}
AAnimal::AAnimal(const AAnimal &other){
    if (this != &other) {
        *this = other;
    }
    std::cout << "Copy AAnimal constructor has been called" << std::endl;
}
AAnimal::~AAnimal(){
    std::cout << "AAnimal destructor called" << std::endl;
}
AAnimal & AAnimal::operator = (const AAnimal &other){
    this->_type = other._type;
    return *this;
}

void AAnimal::makeSound()const{
    std::cout << "Makes generic AAnimal sounds" << std::endl;
}

std::string AAnimal::getType() const {return(_type);}

