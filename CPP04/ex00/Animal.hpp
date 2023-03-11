#pragma once
#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal &other);
    ~Animal();
    Animal & operator = (const Animal &other);

    virtual void    makeSound()const;

    //TODO figure out virtual here
    std::string getType()const;
protected:
    std::string _type;
};
