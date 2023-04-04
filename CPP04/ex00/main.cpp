#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // std::cout << "Constructing three animals with const pointers, one is an animal, one is a dog one is a cat" << std::endl;
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << "The animal where we allocated Dog costructor  " << j->getType() << " " << std::endl;
    // std::cout << "The animal where we allocated Cat constructor "<< i->getType() << " " << std::endl;

    // std::cout << "Cat goes: ";
    // i->makeSound();
    // std::cout << std::endl; //will output the cat sound!
    // std::cout << "Dog goes ";
    // j->makeSound();
    // std::cout << std::endl;

    // std::cout << "And the animal goes ";
    // meta->makeSound();
    // std::cout << std::endl;
    // const WrongAnimal* k = new WrongCat();
    // std::cout << "type of WrongCat: ";
    // k->getType();
    // std::cout << std::endl;
    // std::cout << "wrongCat gives sound of wrongAnimal" << std::endl;
    // k->makeSound();
    // std::cout << std::endl; //will output the Wrong Animal sound!

    std::cout << "Constructing three animals with const pointers, one is an animal, one is a dog one is a cat" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "The animal where we allocated Dog constructor " << j->getType() << " " << std::endl;
    std::cout << "The animal where we allocated Cat constructor "<< i->getType() << " " << std::endl;

    std::cout << "Cat goes ";
    i->makeSound();
    i->getType();
    std::cout << std::endl; //will output the cat sound!
    std::cout << "Dog goes ";
    j->makeSound();
    std::cout << std::endl;
    std::cout << j->getType();
    std::cout << "And the animal goes ";
    meta->makeSound();
    std::cout << std::endl;
    const WrongAnimal* k = new WrongCat();
    std::cout << "type of WrongCat: ";
    std::cout << k->getType();
    std::cout << std::endl;
    std::cout << "+++++wrongCat gives sound of wrongAnimal++++" << std::endl;
    k->makeSound();
    std::cout << std::endl; //will output the Wrong Animal sound!
    return 0;
}