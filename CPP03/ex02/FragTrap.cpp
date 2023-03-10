#include "FragTrap.hpp"

#define ENERGY_COST 1

FragTrap::FragTrap(std::string name): ClapTrap(name){
    this->setHp(100);
    this->setEp(100);
    this->setAttackDmg(30);
    std::cout << "Fragtrap is constructed" << std::endl;
}

FragTrap::~FragTrap(): ~ClapTrap(){
    std::cout << "Fragtrap destructor has been called" << std::endl;
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

