#include "Cat.hpp"

Cat::Cat(): Animal(){
    this->_type = "Cat";
    std::cout << _type << " constructor has ben called" << std::endl;
}
Cat::Cat(const Cat &other){
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "Copy << _type << has been constructed" << std::endl;
}
Cat::~Cat(){
    std::cout << _type <<" destructor called" << std::endl;
}
Cat & Cat::operator = (const Cat &other){

    if (this != &other) {
        this->_type = other._type;
    }
    return *this;
}

void Cat::makeSound(){
    std::cout << "Makes generic " << _type << " sounds" << std::endl;
}

//std::string Cat::getType(){return(this->_type);}