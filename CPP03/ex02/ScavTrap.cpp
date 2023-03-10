#include "ScavTrap.hpp"

#define ENERGY_COST 1

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    this->setHp(100);
    this->setEp(50);
    this->setAttackDmg(20);
    std::cout << "Scavtrap is constructed" << std::endl;
}

ScavTrap::~ScavTrap():~ClapTrap(){
    std::cout << "Scavtrap destructor has been called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & oldObj): ClapTrap(oldObj){
    std::cout << "Copy Claptrap has been constructed" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_ep <= 0) {
        std::cout << "Scavtrap " << this->getName() << " has no energy left and cannot attack" << std::endl;
    }
    else {
        _ep = _ep - ENERGY_COST;
        std::cout << "Scavtrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDmg() << " points of damage!"
                  << std::endl;
    }
}
void ScavTrap::guardGate(){
    std::cout << "Scavtrap "<< _name <<" is now in gate guard mode" << std::endl;
}