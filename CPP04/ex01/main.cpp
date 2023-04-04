#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
 std::cout << "================brain test====================" <<std::endl;

    Brain brain;
    std::cout << "brain getting ideas" << std::endl;
    std::cout << brain.getIdea(7) << std::endl;
    std::cout << brain.getIdea(3) << std::endl;
    std::cout << brain.getIdea(2) << std::endl;
    std::cout << brain.getIdea(1) << std::endl;
    std::cout << "one of the ideas is replaced" << std::endl;
    brain.setIdea(1, "Go rock climibing");
    std::cout << brain.getIdea(1) << std::endl;
 std::cout << "================cat brain test====================" <<std::endl;

    Cat kate;

    std::cout << "Cat kate idea" << std::endl;
    std::cout << kate.getBrain()->getIdea(1) << std::endl;
    kate.getBrain()->setIdea(1, "Reduce carbon footprint");
    std::cout << "Cat kate changes idea" << std::endl;
    std::cout << kate.getBrain()->getIdea(1) << std::endl;
    std::cout << "================leak test====================" <<std::endl;
    const Animal *j = new Cat();
    const Cat *i = new Cat();
    delete j;
    delete i;
    std::cout << "================deep copy test====================" <<std::endl;

    Cat krompus;
    std::cout << "Krompus idea before: " << krompus.getBrain()->getIdea(1) << std::endl;
    krompus.getBrain()->setIdea(1, "Reduce carbon footprint");
    std::cout << "Krompus idea after: " << krompus.getBrain()->getIdea(1) << std::endl;
    Brain *getAddrKrompus = krompus.getBrain();
    std::cout << "Brain address Krompus: " << &getAddrKrompus << std::endl;
    Cat brompus = Cat(krompus);
    Brain *getAddrBrompus = brompus.getBrain();
    std::cout << "Brain address Brompus: " << &getAddrBrompus << std::endl;
    std::cout << "Brompus has the same brain but in diff adress than Krompus" << std::endl;
    std::cout << brompus.getBrain()->getIdea(1) << std::endl;

    std::cout << "=============Assignment opeator test=========";

    Cat* catulus = new Cat();
    Cat* catulus_twin;

    catulus->getBrain()->setIdea(1, "Spend time in nature");
    std::cout << "++++catulus unique idea++++" << std::endl;;
    std::cout << catulus->getBrain()->getIdea(1) << "\n";
    std::cout << "++++ Assign catulus to catulus_twin ***++++" << std::endl;
    catulus_twin = catulus;
    std::cout << "++++ catulus_twin brain after asigment ++++" << std::endl;
    std::cout << catulus_twin->getBrain()->getIdea(1) << "\n";
    delete catulus;
    // delete catulus_twin;

   std::cout << "====One hundread animals test (hakatomb)==========" << std::endl;
   const int NUM_ANIMALS = 100;
   Animal* animals[NUM_ANIMALS];
   for (int i = 0; i < NUM_ANIMALS / 2; i++) {
       animals[i] = new Cat();
   }
   for (int i = NUM_ANIMALS / 2; i < NUM_ANIMALS; i++) {
       animals[i] = new Dog();
   }
   for (int i = 0; i < NUM_ANIMALS; i++) {
       delete animals[i];
   }
   return 0;
}