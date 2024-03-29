#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm(), _name("PresidentialPardonForm"), _signed(false), _signed_grade(25), _execute_grade(5), _target(target)
{
	std::cout << "Constructor of PresidentialPardonForm of " << target << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): _name(other._name), _signed(other._signed), _signed_grade(other._signed_grade), _execute_grade(other._execute_grade)
{
	std::cout << "Copy constructor of PresidentialPardonForm has been called" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &other)
{
	new (this) PresidentialPardonForm(other._target);
	this->_signed = other._signed;
	return (*this);
}

const std::string PresidentialPardonForm::getName()const
{
	return(this->_name);
}
int PresidentialPardonForm::getSignGrade()const
{
	return(this->_signed_grade);
}
int PresidentialPardonForm::getExecuteGrade()const
{
	return(this->_execute_grade);
}

bool PresidentialPardonForm::checkSignature()const
{
	return(this->_signed);
}

std::string PresidentialPardonForm::getTarget ()const
{
	return(this->_target);
}
void PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat)
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

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const &PresidentialPardonForm)
{
	o << PresidentialPardonForm.getName() << "\n";
	o << "Target: " << PresidentialPardonForm.getTarget() << "\n";
	o << "Grade of bureucrat to sign: " << PresidentialPardonForm.getSignGrade() << "\n";
	o << "Grade of bureucrat to execute: " << PresidentialPardonForm.getExecuteGrade() << "\n";
	o << "Grade with signature(1 for signed): " << PresidentialPardonForm.checkSignature() << "\n";
	return o;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if(this->checkSignature() && executor.getGrade() <= this->getExecuteGrade())
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphon Beeblebrox" << std::endl;
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
