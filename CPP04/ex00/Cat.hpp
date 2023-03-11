#pragma once
#include <iostream>

class Cat : public Animal
{
public:
    Cat(std::string name);
    Cat(const Cat &oldObj);
    ~Cat();
    Cat & operator = (const Cat &other);

    makeSound();
protected:
    std::string type;
};