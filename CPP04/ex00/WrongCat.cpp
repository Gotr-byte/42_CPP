#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
    this->_wrongType = "WrongCat";
    std::cout << _wrongType << " constructor has ben called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other){
    if (this != &other) {
        this->_wrongType = other._wrongType;
    }
    std::cout << "Copy << _wrongType << has been constructed" << std::endl;
}
WrongCat::~WrongCat(){
    std::cout << _wrongType <<" destructor called" << std::endl;
}
WrongCat & WrongCat::operator = (const WrongCat &other){

    if (this != &other) {
        this->_wrongType = other._wrongType;
    }
    return *this;
}

void WrongCat::makeSound()const{
    std::cout << "Makes generic " << _wrongType << " sounds" << std::endl;
}

std::string WrongCat::getType(){return(this->_wrongType);}