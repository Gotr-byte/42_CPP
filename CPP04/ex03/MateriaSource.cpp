#include "MateriaSource.hpp"
#include <string>
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->_slots[i] = NULL;
	}
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
	for(int i = 0; i < 4; i++)
	{	
		if(other._slots[i] != NULL)
			_slots[i] = other._slots[i]->clone();
	}
	std::cout << "Copy constructor of materia source called\n";
}
MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_slots[i] != NULL)
		{
			delete _slots[i];
		}
		this->_slots[i] = NULL;
	}
	std::cout << "Materia source destructor called\n";
}

MateriaSource & MateriaSource::operator = (const MateriaSource &other)
{
	for(int i = 0; i < 4; i++)
	{	if(_slots[i] != NULL)
			_slots[i] = other._slots[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* AMateria)
{
	for(int i = 0; i < 4; i++)
	{
		if (_slots[i] == NULL)
		{
			_slots[i] = AMateria;
			std::cout << "Learned AMateria type " << _slots[i]->getType() << "\n";
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if(_slots[i] != NULL && type == _slots[i]->getType())
		{
			std::cout << "Created materia of type " << _slots[i]->getType() << std::endl;
			return (_slots[i]->clone());
		}
	}
	std::cout << "Could not create materia of type " << type << std::endl;
	return (NULL);
}