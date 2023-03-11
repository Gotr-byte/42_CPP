#pragma once
#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    ~WrongAnimal();
    WrongAnimal & operator = (const WrongAnimal &other);

    void    makeSound()const;

    //TODO figure out virtual here
    std::string getType()const;
protected:
    std::string _wrongType;
};
