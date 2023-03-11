#pragma once
#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    ~Animal();
    Animal & operator = (const Animal &other);

    void    makeSound();

    //TODO figure out virtual here
    virtual std::string getType();
protected:
    std::string _type;
};
