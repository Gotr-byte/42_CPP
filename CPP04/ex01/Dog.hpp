#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal
{
public:
    Dog();
    Dog(const Dog &other);
    ~Dog();
    Dog & operator = (const Dog &other);

    void makeSound() const;
    std::string getType()const;
    Brain *getBrain();

private:
    std::string _type;
    Brain*      _brain;
};