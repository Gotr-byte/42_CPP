#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal(){
   this->_type = "Dog";
    _brain = new Brain();
    std::cout <<"Dog constructor has ben called" << std::endl;
}
Dog::Dog(const Dog &other): Animal(){
    if(this != &other)
    {
        _type = "Dog";
        _brain = new Brain();
        for(int i = 0; i < 100; i++)
            _brain->setIdea(i, other._brain->getIdea(i));
        std::cout << "Copy Dog constructor has been called" << std::endl;
    }
}
Dog::~Dog(){
    delete this->_brain;
    std::cout << "Dog destructor called" << std::endl;
}
Dog & Dog::operator = (const Dog &other){
    if(this != &other)
        {
            _type = "Dog";
            _brain = new Brain();
            for(int i = 0; i < 100; i++)
                _brain->setIdea(i, other._brain->getIdea(i));
            std::cout << "Dog overloaded assignment operator called" << std::endl;
        }
    return *this;
}

void Dog::makeSound()const{
    std::cout << "Makes generic " << _type << " sounds" << std::endl;
}

std::string Dog::getType() const {return(this->_type);}

Brain* Dog::getBrain()
{
    return (this->_brain);
}