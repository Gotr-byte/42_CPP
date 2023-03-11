#pragma once
#include <iostream>

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &oldObj);
    ~Cat();
    Cat & operator = (const Cat &other);

    makeSound();
protected:
    std::string _type;
};