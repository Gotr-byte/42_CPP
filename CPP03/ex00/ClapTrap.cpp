#include "ClapTrap.hpp"

ClapTrap(std::string name):_name(name), _hp(10), _ep(10), _attack_dmg(0){
    std::cout << "Claptrap is constructed" << std::endl;
}
ClapTrap(const ClapTrap &oldObj){
    std::cout << "Copy Claptrap has been constructed" << std::endl;
}
~ClapTrap(){
    std::cout << "Claptrap destructor called" << std::endl;
}
ClapTrap & operator = (const ClapTrap &assign){
    //todo assign values from right to left
     return(*this);
}

void    ClapTrap::attack(const std::string& target){
    if (_ep == 0)
        return;
    _ep = _ep - 1;
    std::cout << "Claptrap" << _name << "attacks" target << "causing" << _attack_dmg << "points of damage!" << std::endl;
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
    _hp = _hp + amount;
    _ep = _ep - 1;
    if (_ep <= 0)
        std::cout << "Claptrap " << _name << "has no energy left and cannot conduct repairs" << std::endl;
    std::cout << "Claptrap "<< name << " is fixed for "<< amount << " hit points" << std::endl;
}