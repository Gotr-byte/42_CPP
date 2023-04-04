#pragma once
#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &other);
    ~Cat();
    Cat & operator = (const Cat &other);

    void makeSound()const;
    std::string getType();

private:
    std::string _type;
};