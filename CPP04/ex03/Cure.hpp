#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
    Cure();
    Cure(const Cure &other);
    ~Cure();
    Cure & operator = (const Cure &other);
	std::string const & getType() const;
	Cure* clone() const;
	void use(ICharacter& target);

	private:
		std::string _type;
};