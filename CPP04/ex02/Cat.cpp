#include "Cat.hpp"

Cat::Cat(): AAnimal(){
   this->_type = "Cat";
    _brain = new Brain();
    std::cout <<"Cat constructor has ben called" << std::endl;
}
Cat::Cat(const Cat &other): AAnimal(){
    if(this != &other)
    {
        _type = "Cat";
        _brain = new Brain();
        for(int i = 0; i < 100; i++)
            _brain->setIdea(i, other._brain->getIdea(i));
        std::cout << "Copy cat constructor has been called" << std::endl;
    }
}
Cat::~Cat(){
    delete this->_brain;
    std::cout << "Cat destructor called" << std::endl;
}
Cat & Cat::operator = (const Cat &other){
    if(this != &other)
        {
            _type = "Cat";
            _brain = new Brain();
            for(int i = 0; i < 100; i++)
                _brain->setIdea(i, other._brain->getIdea(i));
            std::cout << "Cat overloaded assignment operator called" << std::endl;
        }
    return *this;
}

void Cat::makeSound()const{
    std::cout << "Makes generic " << _type << " sounds" << std::endl;
}

std::string Cat::getType() const {return(this->_type);}

Brain* Cat::getBrain()
{
    return (this->_brain);
}