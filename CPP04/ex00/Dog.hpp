#pragma once
#include <iostream>

class Dog: public Animal
{
public:
    Dog(std::string name);
    Dog(const Dog &oldObj);
    ~Dog();
    Dog & operator = (const Dog &other);

    makeSound();
private:
};