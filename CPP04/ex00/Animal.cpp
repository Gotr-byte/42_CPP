#include "Animal.hpp"

Animal::Animal(std::string name):_type(name){
    std::cout << "Animal is constructed" << std::endl;
}
Animal::Animal(const Animal &other){
    if (this != &other) {
        this->_type = other._type;
    }
    std::cout << "Copy Animal has been constructed" << std::endl;
}
Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}
Animal & Animal::operator = (const Animal &other){

    if (this != &other) {
        // Copy the data members from 'other' to 'this'
        this->_name = other._name;
        this->_hp = other._hp;
        this->_ep = other._ep;
        this->_attack_dmg = other._attack_dmg;
    }
    return *this;
}
