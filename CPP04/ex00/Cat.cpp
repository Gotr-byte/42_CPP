#include "Cat.hpp"

Cat::Cat():_type("Cat"):{
    std::cout << "Cat is constructed" << std::endl;
}
Cat::Cat(const Cat &other){
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "Copy Cat has been constructed" << std::endl;
}
Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
}
Cat & Cat::operator = (const Cat &other){

    if (this != &other) {
        // Copy the data members from 'other' to 'this'
        this->_name = other._name;
        this->_hp = other._hp;
        this->_ep = other._ep;
        this->_attack_dmg = other._attack_dmg;
    }
    return *this;
}

Cat::makeSound(){
    std::cout "Makes " << _type << " sounds" << std::endl;
}