#include "Character.hpp"

Character::Character() : ICharacter()
{
	for (int i = 0; i < 4; i++)
	{
		this->_slots[i] = NULL;
	}
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string name) : ICharacter()
{
	for (int i = 0; i < 4; i++)
	{
		this->_slots[i] = NULL;
	}
	this->_name = name;
	std::cout << "Character constructor of "<< _name << std::endl;
}
Character::Character(const Character &other) : ICharacter()
{
	if(this != &other)
	{
		_name = other.getName();
		for (int i = 0; i < 4; i++)
		{if(other._slots[i] != nullptr)
			this->_slots[i] = other._slots[i]->clone();
		}
	}
	std::cout << "Character copy constructor called" << std::endl;
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i] != NULL)
			delete _slots[i];
		_slots[i] == NULL;
	}
	std::cout << "Character destructor called" << std::endl;
}
Character &Character::operator=(const Character &other)
{
	if(this != &other)
	{
	this->_name = other.getName();
	for(int i = 0; i < 4; i++)
	{	if(_slots[i] != NULL)
			_slots[i] = other._slots[i]->clone();
	}
	}
	return *this;
}
void Character::setName(std::string name)
{
	this->_name = name;
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::printEquip(int i)
{
	if (this->_slots[i] == NULL)
		std::cout << "Equipment slot empty \n";
	else
		std::cout << "Equipment in slot number: " << i << " is " << this->_slots[i]->getType() << "\n";
}
void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_slots[i] == NULL)
		{
			_slots[i] = m;
			std::cout << _name << " equiped " << m->getType() << "\n";
			break;
		}
	}
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _slots[idx] == NULL)
		return;
	this->_slots[idx] = NULL;
}
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || _slots[idx] == NULL)
		return;
	// std::cout << "character use memeber function called " << std::endl;
	this->_slots[idx]->use(target);
}
