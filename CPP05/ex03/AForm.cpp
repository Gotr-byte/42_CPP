#include "AForm.hpp"

AForm::AForm(): _name("Default"), _signed(false), _signed_grade(1), _execute_grade(1)
{
	std::cout << "Constructor of AForm called" << std::endl;
}
AForm::AForm(const AForm &other): _name(other.getName()), _signed(other.checkSignature()), _signed_grade(other.getSignGrade()), _execute_grade(other.getExecuteGrade())
{
	std::cout << "Copy constructor of AForm has been called" << std::endl;
}
AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}
AForm & AForm::operator = (const AForm &other)
{
	if (this != &other) {
        *this = other;
    }
	return (*this);
}

const std::string AForm::getName()const
{
	return(this->_name);
}
int AForm::getSignGrade()const
{
	return(this->_signed_grade);
}
int AForm::getExecuteGrade()const
{
	return(this->_execute_grade);
}

bool AForm::checkSignature()const
{
	return(this->_signed);
}

// the following needs to be implemented
// const std::string	_name;
// 		bool				_signed;
// 		const int			_signed_grade;
// 		const int			_execute_grade;
std::ostream & operator<<(std::ostream & o, AForm const &form)
{
	o << "AForm name: " << form.getName() << "\n";
	o << "Grade of bureucrat to sign: " << form.getSignGrade() << "\n";
	o << "Grade of bureucrat to execute: " << form.getExecuteGrade() << "\n";
	o << "Grade with signature(1 for signed): " << form.checkSignature() << "\n";
	return o;
}

<<<<<<< HEAD
// void Form::beSigned(Bureaucrat &bureaucrat)
// {
// 	if (bureaucrat.getGrade() < this->_signed_grade)
// 	{
// 		this->_signed = true;
// 		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because his grade was too low." << std::endl;
// 	}
// }
void AForm::beSigned(Bureaucrat &bureaucrat)
{
	(void)bureaucrat;
	std::cout << "Form is signed by bureaucrat here\n";
}

void AForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << "Form is executed by bureaucrat here\n";
}
