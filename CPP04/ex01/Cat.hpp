#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &other);
    ~Cat();
    Cat & operator = (const Cat &other);

    void makeSound()const;
    std::string getType()const;
    Brain *getBrain();

private:
    std::string _type;
    Brain*      _brain;
};