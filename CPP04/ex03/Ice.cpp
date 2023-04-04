#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice constructor called" << std::endl;
}
Ice::Ice(const Ice &other)
{
	_type = other.getType();
}
Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}
Ice &Ice::operator=(const Ice &other)
{
	_type = other.getType();
	return *this;
}

std::string const &Ice::getType() const
{
	return (this->_type);
}

Ice *Ice::clone() const
{
	Ice* iceClone = new Ice();
	return (iceClone);
}

void Ice::use(ICharacter &target)
{
	std::cout << "shoots an ice bolt at " << target.getName() << std::endl;
}