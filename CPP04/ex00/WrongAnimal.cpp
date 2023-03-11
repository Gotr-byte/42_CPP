#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_wrongType("WrongAnimal"){
    std::cout << _wrongType <<" is constructed" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &other){
    if (this != &other) {
        this->_wrongType = other._wrongType;
    }
    std::cout << "Copy " << _wrongType << " has been constructed" << std::endl;
}
WrongAnimal::~WrongAnimal(){
    std::cout << _wrongType << " destructor called" << std::endl;
}
WrongAnimal & WrongAnimal::operator = (const WrongAnimal &other){

    if (this != &other) {
        this->_wrongType = other._wrongType;
    }
    return *this;
}

void WrongAnimal::makeSound()const{
    std::cout << "Makes generic " << _wrongType << " sounds" << std::endl;
}

std::string WrongAnimal::getType()const{return(_wrongType);}