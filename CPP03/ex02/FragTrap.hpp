#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
public:
    FragTrap(std::string name);
    ~FragTrap();

    void attack(const std::string& target);
    void highFiveGuys();
};