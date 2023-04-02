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
    virtual std::string getType()const;

    //TODO figure out virtual here

protected:
    std::string _type;
};
