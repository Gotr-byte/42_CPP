#pragma once
#include <iostream>
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();
	MateriaSource & operator = (const MateriaSource &other);
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
protected:
	AMateria* _slots[4];
};