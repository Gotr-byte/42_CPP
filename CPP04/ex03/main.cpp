#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// int main()
// {
// 	std::cout << "+++Cure and Ice materia creation+++" << std::endl;
// 	AMateria *cure = new Cure();
// 	AMateria *ice = new Ice();
// 	std::cout << "Cure AMateria type is: " << cure->getType() << std::endl;
// 	std::cout << "Ice AMateria type is: " << ice->getType() << std::endl;
// 	std::cout << "+++Cure and Ice clone test+++" << std::endl;
// 	AMateria *cure_clone = cure->clone();
// 	std::cout << "Cure clone type is: " << cure_clone->getType() << std::endl;
// 	delete cure_clone;
// 	delete cure;
// 	delete ice;
// 	ICharacter* luke = new Character("Luke");
// 	std::cout << "The heroes name is " << luke->getName() << "\n";
// 	ICharacter* han = new Character("han");
// 	std::cout << "The villains name is " << han->getName() << "\n";
// 	luke->equip(ice);
	// luke->use(0, *han);
	// luke->equip(cure);
	// luke->printEquip(0);
	// luke->unequip(0);
	// luke->printEquip();
	// luke->use(1, *han);
// 	delete luke;
// 	delete han;
// }

int main()
{
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;
return 0;
}