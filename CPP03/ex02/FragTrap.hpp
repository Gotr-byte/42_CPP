#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();
    FragTrap(const FragTrap &oldObj);
    FragTrap & operator = (const FragTrap &other);

    void attack(const std::string& target);
    void highFiveGuys();
};