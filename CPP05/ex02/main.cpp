#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


int main()
{
	PresidentialPardonForm test("Gump");
	std::cout << test;
	// AForm *test = PresidentialPardonForm("Forrest");
	Bureaucrat a("Jenkins", 1);
	std::cout << "Bureaucrat signs the document\n";
	try
	{
		test.beSigned(a);
	}
	catch(...)
	{
		std::cerr << e.what();
	}
	

	
}
