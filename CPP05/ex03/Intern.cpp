#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"



Intern::Intern(){}
Intern::Intern(const Intern &other){}
Intern::~Intern(){}
Intern & Intern::operator = (const Intern &other){return(*this);}

AForm*		Intern::makeForm(std::string name, std::string target)
{
	AForm* form = NULL;
	std::string documents[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	
	int i = 0;
	while (i < 3 && documents[i] != name)
		i++;

	switch (i) 
	{
		case 0:
			form = new PresidentialPardonForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			std::cerr << "Intern error: Form does not exist! \n";
			break;
	}
	return(form);
}
