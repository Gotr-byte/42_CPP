#pragma once
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character &other);
		~Character();
		Character & operator = (const Character &other);

		void printEquip(int i);
		void setName(std::string name);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	
	private:
		std::string _name;
		AMateria	*_slots[4];
};