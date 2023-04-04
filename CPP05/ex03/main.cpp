#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// "presidential pardon", "robotomy request", "shrubbery creation"
int main()
{
	Intern intern;

	AForm*  ppf;
	AForm*  rrf;
	AForm*  scf;
	AForm*  bug;
	ppf = intern.makeForm("presidential pardon", "Tree Bug");
	rrf = intern.makeForm("robotomy request", "Ant");
	scf = intern.makeForm("shrubbery creation", "Dog");
	bug = intern.makeForm("shrubbery creations", "Dogs");

	std::cout << *ppf;
	Bureaucrat a("Jenkins", 5);
	Bureaucrat b("Jenner", 6);
	Bureaucrat c("Failey", 149);
	std::cout << "Bureaucrat signs the document\n";
	try
	{
		std::cout << a;
		(*ppf).beSigned(a);
		std::cout << *ppf;
	}
		catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	delete ppf;
	delete rrf;
	delete scf;
}
