#include "Bureaucrat.hpp"


int main()
{
	std::cout << "The grade is too high\n";
	try
	{
		Bureaucrat m("Jenkins", -11);
		std::cout << m;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "The grade is ok\n";
	try
	{
		Bureaucrat m("Jenkins", 111);
		std::cout << m;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "The grade is too low\n";
	try
	{
		Bureaucrat m("Jenkins", 711);
		std::cout << m;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << std::endl;
	std::cout << "Grade to high expected" << std::endl;
	try
	{	
		Bureaucrat j("John Doe", 1);
		std::cout << j;
		j.setGrade(3);
		std::cout << j;
		j.setGrade(-1);
		std::cout << j;
		j.setGrade(151);
		std::cout << j;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what();
	}
	std::cout << "Grade to high test ended" << std::endl;
	std::cout << std::endl;
	std::cout << "Grade to low expected" << std::endl;
	try
	{	
		Bureaucrat k("Cesare", 1);
		std::cout << k;
		k.setGrade(3);
		std::cout << k;
		k.setGrade(151);
		std::cout << k;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what();
	}
	std::cout << "Grade to low test ended" << std::endl;
	std::cout << std::endl;
	std::cout << "Grade to high test" << std::endl;
	Bureaucrat i;
	try
	{	
		i.setGrade(1);
		std::cout << i;
		i.setGrade(3);
		std::cout << i;
		i.setGrade(-1);
		std::cout << i;
		i.setGrade(151);
		std::cout << i;
	}
	
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << "Grade to high test ended" << std::endl;
	std::cout << std::endl;
	std::cout << "Incrementation / decrementation test, expected grade too low\n";
	try
	{	
		Bureaucrat m("Momo", 149);
		std::cout << m;
		m.incrementGrade();
		std::cout << m;
		m.decrementGrade();
		std::cout << m;
		m.decrementGrade();
		std::cout << m;
		m.decrementGrade();
		std::cout << m;
		m.decrementGrade();
		std::cout << m;
		m.decrementGrade();
		std::cout << m;
		m.incrementGrade();
		std::cout << m;
		m.incrementGrade();
		std::cout << m;
		m.incrementGrade();
		std::cout << m;
		m.setGrade(300);
		std::cout << m;
		m.setGrade(-1);
		std::cout << m;
		m.setGrade(151);
		std::cout << m;
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
	std::cout << "Decremented to a grade which is too low\n";
	std::cout << std::endl;
}
