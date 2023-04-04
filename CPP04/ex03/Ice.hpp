#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
    Ice();
    Ice(const Ice &other);
    ~Ice();
    Ice & operator = (const Ice &other);
	std::string const & getType() const;
	Ice* clone() const;
	void use(ICharacter& target);

	private:
		std::string _type;
};