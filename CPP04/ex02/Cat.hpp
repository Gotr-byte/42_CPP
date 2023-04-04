#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal
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