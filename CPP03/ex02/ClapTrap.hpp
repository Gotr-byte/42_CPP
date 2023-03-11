#pragma once
#include <iostream>

class ClapTrap
{
public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &oldObj);
    ~ClapTrap();
    ClapTrap & operator = (const ClapTrap &other);

    void        attack(const std::string& target);
    void        takeDamage(unsigned int amount);
    void        beRapaired(unsigned int amount);
    std::string getName();
    int         getHp();
    int         getEp();
    int         getAttackDmg();
    void        setName(std::string name);
    void        setHp(int hp);
    void        setEp(int ep);
    void        setAttackDmg(int attackDmg);
    void        getData();

protected:
    std::string _name;
    int         _hp;
    int         _ep;
    int         _attack_dmg;
};