#include "ClapTrap.hpp"

#define ENERGY_COST 1

ClapTrap::ClapTrap(std::string name):_name(name), _hp(10), _ep(10), _attack_dmg(0){
    std::cout << "Claptrap is constructed" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other){
    if (this != &other) {
        // Copy the data members from 'other' to 'this'
        this->_name = other._name;
        this->_hp = other._hp;
        this->_ep = other._ep;
        this->_attack_dmg = other._attack_dmg;
    }
    std::cout << "Copy Claptrap has been constructed" << std::endl;
}
ClapTrap::~ClapTrap(){
    std::cout << "Claptrap destructor called" << std::endl;
}
ClapTrap & ClapTrap::operator = (const ClapTrap &other){

    if (this != &other) {
        // Copy the data members from 'other' to 'this'
        this->_name = other._name;
        this->_hp = other._hp;
        this->_ep = other._ep;
        this->_attack_dmg = other._attack_dmg;
    }
    return *this;
}

std::string ClapTrap::getName() {return(this->_name);}
int ClapTrap::getAttackDmg() {return(this->_attack_dmg);}
int ClapTrap::getEp() {return(this->_ep);}
int ClapTrap::getHp() {return(this->_hp);}

void    ClapTrap::attack(const std::string& target){
    if (_ep <= 0)
    {
        std::cout << "Claptrap " << _name << " has no energy left and cannot attack" << std::endl;
    }
    else
    {
        _ep = _ep - ENERGY_COST;
        std::cout << "Claptrap " << _name << " attacks " << target << " causing " << _attack_dmg << " points of damage!" << std::endl;
    }
}
void    ClapTrap::takeDamage(unsigned int amount){

    _hp = _hp - amount;
    if (_hp <= 0)
    {
        std::cout <<"Claptrap zero or less hp left which means he is basically dead" << std::endl;
        return ;
    }
    std::cout << "Claptrap takes " << amount << " damage!" << std::endl;
}
void    ClapTrap::beRapaired(unsigned int amount){
    if (_ep <= 0)
    {
        std::cout << "Claptrap " << _name << " has no energy left and cannot conduct repairs" << std::endl;
    }
    else{
        _hp = _hp + amount;
        _ep = _ep - ENERGY_COST;
        std::cout<< "Claptrap "<< _name << " is fixed for "<< amount << " hit points" << std::endl;
    }

}