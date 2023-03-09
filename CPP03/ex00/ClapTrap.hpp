#pragma once
#include <iostream>

class ClapTrap
{
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &oldObj);
    ~ClapTrap();
    ClapTrap & operator = (const ClapTrap &assign);

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRapaired(unsigned int amount);
private:
    std::string _name;
    int         _hp;
    int         _ep;
    int         _attack_dmg;
};