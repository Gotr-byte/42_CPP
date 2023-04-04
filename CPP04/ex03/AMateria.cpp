#include "AMateria.hpp"


AMateria::AMateria(std::string const & type):_type(type){}

AMateria::AMateria(){
	// std::cout << "AMateria constructor called" << std::endl;
}
AMateria::AMateria(const AMateria &other)
{
	_type = other._type;
}
AMateria::~AMateria()
{
	// std::cout << "AMateria destructor called" << std::endl;
}
AMateria & AMateria::operator = (const AMateria &other)
{
	_type = other._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return(this->_type);
}
