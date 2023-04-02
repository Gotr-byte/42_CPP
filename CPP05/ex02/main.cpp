#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{
	PresidentialPardonForm test("Gump");
	PresidentialPardonForm test_too("Forrest");
	RobotomyRequestForm test_three("Connor");
	RobotomyRequestForm unsigned_form("Sarah");
	ShrubberyCreationForm test_five("House");

	std::cout << test;
	Bureaucrat a("Jenkins", 5);
	Bureaucrat b("Jenner", 6);
	Bureaucrat c("Failey", 149);
	std::cout << "Bureaucrat signs the document\n";
	try
	{
		std::cout << a;
		test.beSigned(a);
		std::cout << test;
	}
		catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "+++Bureaucrat executes the document+++\n";
	try
	{
		std::cout << a;
		test.execute(a);
		std::cout << test;
	}
		catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "Bureucrat fails to execute\n";
	try
	{
		std::cout << b;
		test.execute(b);
		std::cout << test;
	}
		catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << "Bureucrat fails to execute due to lack of signature\n";
	try
	{
		std::cout << b;
		test_too.execute(b);
		std::cout << test;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << "Failed to execute\n";
	try
	{
		b.executeForm(test);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "Failed to execute due to lack of signature\n";
	try
	{
		a.executeForm(test_too);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "Managed to execute\n";
	try
	{
		a.executeForm(test);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Robotomy signed and executed\n";
	try
	{
		test_three.beSigned(a);
		a.executeForm(test_three);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Robotomy not executed\n";
	try
	{
		c.executeForm(test_three);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "Shrubbery form signed and executed\n";
	try
	{
		test_five.beSigned(a);
		a.executeForm(test_five);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;




	
}
