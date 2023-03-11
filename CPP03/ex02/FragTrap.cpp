#include "FragTrap.hpp"

#define ENERGY_COST 1

FragTrap::FragTrap(std::string name): ClapTrap(name){
    this->setHp(100);
    this->setEp(50);
    this->setAttackDmg(20);
    std::cout << "FragTrap is constructed" << std::endl;
}
FragTrap::FragTrap(const FragTrap & oldObj): ClapTrap(oldObj) {
    std::cout << "Copy Claptrap has been constructed" << std::endl;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor has been called" << std::endl;
}
FragTrap & FragTrap::operator = (const FragTrap &other){

    if (this != &other) {
        this->_name = other._name;
        this->_hp = other._hp;
        this->_ep = other._ep;
        this->_attack_dmg = other._attack_dmg;
    }
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (_ep <= 0) {
        std::cout << "Fragtrap " << this->getName() << " has no energy left and cannot attack" << std::endl;
    }
    else {
        _ep = _ep - ENERGY_COST;
        std::cout << "Fragtrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDmg() << " points of damage!"
                  << std::endl;
    }
}
void FragTrap::highFiveGuys(){
    std::cout << "Fragtrap "<< _name <<" holds out his arm and yells 'HIGH FIVE' and everyone ignores him..." << std::endl;
}

