#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}
Cure::Cure(const Cure &other)
{
	_type = other._type;
}
Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}
Cure &Cure::operator=(const Cure &other)
{
	_type = other._type;
	return *this;
}

std::string const &Cure::getType() const
{
	return (this->_type);
}

Cure *Cure::clone() const
{
	Cure *cure_clone = new Cure();
	return cure_clone;
}

void Cure::use(ICharacter &target)
{
	std::cout << "heals " << target.getName() << " wounds" << std::endl;
}