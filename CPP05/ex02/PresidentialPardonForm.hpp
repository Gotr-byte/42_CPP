#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm(), _name("PresidentialPardonForm"), _signed(false), _signed_grade(25), _execute_grade(5)
{
	std::cout << "Constructor of PresidentialPardonForm called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string name, const int signed_grade, const int execute_grade): _name(name), _signed(false), _signed_grade(signed_grade), _execute_grade(execute_grade)
{
	if (_signed_grade < 0)
		throw(GradeTooHighException());
	else if (_signed_grade > 150)
		throw(GradeTooLowException());
	if (_execute_grade < 0)
		throw(GradeTooHighException());
	else if (_execute_grade > 150)
		throw(GradeTooLowException());
	std::cout << "Constructor of PresidentialPardonForm called" << std::endl;
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
	new (this) PresidentialPardonForm(other.getName(), other.getSignGrade(), other.getExecuteGrade());
	this->_signed = other._signed;
	return (*this);
}

const std::string PresidentialPardonForm::getName()const
{
	return(this->_name);
}
const int PresidentialPardonForm::getSignGrade()const
{
	return(this->_signed_grade);
}
const int PresidentialPardonForm::getExecuteGrade()const
{
	return(this->_execute_grade);
}
void PresidentialPardonForm::beSigned(Bureaucrat &bureaucrat, std::string target)
{
	if (bureaucrat.getGrade() < this->_signed_grade)
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		std::cout << target << "has been pardoned by Zaphon Beeblebrox" << std::endl
	}
	else
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->getName() << " because his grade was too low." << std::endl;
	}
}

// the following needs to be implemented
// const std::string	_name;
// 		bool				_signed;
// 		const int			_signed_grade;
// 		const int			_execute_grade;
std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const &PresidentialPardonForm)
{
	o << "PresidentialPardonForm name: " << PresidentialPardonForm.getName() << "\n";
	o << "Grade of bureucrat to sign: " << PresidentialPardonForm.getSignGrade() << "\n";
	o << "Grade of bureucrat to execute: " << PresidentialPardonForm.getExecuteGrade() << "\n";
	return o;
}