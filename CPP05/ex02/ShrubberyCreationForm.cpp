#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm(), _name("ShrubberyCreationForm"), _signed(false), _signed_grade(145), _execute_grade(137), _target(target)
{
	std::cout << "Constructor of ShrubberyCreationForm of " << target << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): _name(other._name), _signed(other._signed), _signed_grade(other._signed_grade), _execute_grade(other._execute_grade)
{
	std::cout << "Copy constructor of ShrubberyCreationForm has been called" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm &other)
{
	new (this) ShrubberyCreationForm(other._target);
	this->_signed = other._signed;
	return (*this);
}

const std::string ShrubberyCreationForm::getName()const
{
	return(this->_name);
}
int ShrubberyCreationForm::getSignGrade()const
{
	return(this->_signed_grade);
}
int ShrubberyCreationForm::getExecuteGrade()const
{
	return(this->_execute_grade);
}

bool ShrubberyCreationForm::checkSignature()const
{
	return(this->_signed);
}

std::string ShrubberyCreationForm::getTarget ()const
{
	return(this->_target);
}
void ShrubberyCreationForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() < this->_signed_grade)
	{
		this->_signed = true;
		bureaucrat.signForm(*this);
	}
	else
	{
		bureaucrat.signForm(*this);
		throw(GradeTooLowException());
	}
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const &ShrubberyCreationForm)
{
	o << ShrubberyCreationForm.getName() << "\n";
	o << "Target: " << ShrubberyCreationForm.getTarget() << "\n";
	o << "Grade of bureucrat to sign: " << ShrubberyCreationForm.getSignGrade() << "\n";
	o << "Grade of bureucrat to execute: " << ShrubberyCreationForm.getExecuteGrade() << "\n";
	o << "Grade with signature(1 for signed): " << ShrubberyCreationForm.checkSignature() << "\n";
	return o;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if(this->checkSignature() && executor.getGrade() <= this->getExecuteGrade())
	{
		std::ofstream fout(this->getTarget()+"_shrubbery");
		fout << "        @@@         @@@\n";
		fout << "       @@@@@       @@@@@\n";
		fout << "        @@@         @@@\n";
		fout << "         |           |\n";
		fout << "================================\n";
	}
	else if(!this->checkSignature())
	{
		throw (FormNotSignedException());
	}
	else if(executor.getGrade() > this->getExecuteGrade())
	{
		throw(GradeTooLowException());
	}
}