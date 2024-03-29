#include "Form.hpp"


int main()
{
	std::cout << "testing the form \n";
	try
	{
		Form test("test", 111, 112);
		std::cout << test;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << "\n";
	Form test_too("test_too", 50, 100);
	Form test_three("test_three", 50, 100);
	Form test_four("test_four", 50, 100);
	Form test_five("test_four", 50, 100);

	Bureaucrat a("Jenkins", 10);
	try
	{
		Form test_one("test_one",111,12);
		std::cout << test_one;
		std::cout << "Bureaucrat signes document because his grade is high enough..." << '\n';
		a.setGrade(10);
		std::cout << test_one;
		std::cout << a;
		test_one.beSigned(a);
		std::cout << test_one;
		std::cout << test_too;
		std::cout << a;
		test_too.beSigned(a);
		std::cout << test_too;
		std::cout << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	try
	{
		std::cout << "Buereaucrat does not sign document because he is of too low grade..." << '\n';
		a.setGrade(60);
		test_three.beSigned(a);
		test_four.beSigned(a);
		std::cout << std::endl;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	try
	{
		std::cout << "Verifying if the exceptions work in case grade ofform beeing too high to sign" << '\n';
		Form test_five("test_three", -1, 15);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "Verifying if the exceptions work in case of form having too low grade to sign" << '\n';
	try
	{
		Form test_six("test_four", 151, 15);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;

	std::cout << "Copy constructor test\n";
	Form *Fptr = new Form(test_too);
	std::cout << *Fptr;
	delete Fptr;
}
