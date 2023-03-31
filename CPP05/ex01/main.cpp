#include "Form.hpp"


int main()
{
	Form test;
	Form test_too("test_too", 50, 100);
	Bureaucrat a("Jenkins");
	std::cout << "Bureaucrat signes document because his grade is high enough..." << '\n';
	a.setGrade(10);
	std::cout << test;
	std::cout << a;
	test.beSigned(a);
	std::cout << test_too;
	std::cout << a;
	test_too.beSigned(a);
	std::cout << std::endl;
	std::cout << "Buereaucrat does not sign document because he is of too low grade..." << '\n';
	a.setGrade(60);
	test.beSigned(a);
	test_too.beSigned(a);
	std::cout << std::endl;
	std::cout << "Verifying if the exceptions work in this case" << '\n';
	try
	{
		Form test_three("test_three", -1, 15);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "Verifying if the exceptions work in this case" << '\n';
	try
	{
		Form test_four("test_four", 151, 15);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
}
