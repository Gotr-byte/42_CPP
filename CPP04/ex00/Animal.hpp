#pragma once
#include <iostream>

class Animal
{
public:
    Animal(std::string name);
    Animal(const Animal &other);
    ~Animal();
    Animal & operator = (const Animal &other);
    makeSound();
protected:
    _type
};
