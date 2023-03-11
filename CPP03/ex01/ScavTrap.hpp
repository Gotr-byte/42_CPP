#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &oldObj);
    ~ScavTrap();
    ScavTrap & operator = (const ScavTrap &other);

    void attack(const std::string& target);
    void guardGate();
};