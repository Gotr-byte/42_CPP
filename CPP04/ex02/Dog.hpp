#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public AAnimal
{
public:
    Dog();
    Dog(const Dog &other);
    ~Dog();
    Dog & operator = (const Dog &other);

    void makeSound() const;
    std::string getType()const;
    Brain *getBrain();

protected:
    std::string _type;
    Brain*      _brain;
};