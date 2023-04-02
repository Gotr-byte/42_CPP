#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Cat.hpp"

/*Test copy constructor, test the overloaded equal sign operator*/
int main() {
    std::cout << "============ Trying to instantiate abstact class =======" << std::endl;
    const AAnimal *ok = new Cat();
    delete ok;
    // const AAnimal *wrong = new AAnimal();
    // delete wrong;
}