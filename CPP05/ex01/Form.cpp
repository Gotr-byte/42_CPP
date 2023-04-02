#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _signed_grade(50), _execute_grade(20)
{
	std::cout << "Constructor of Form called" << std::endl;
}
Form::Form(const std::string name, const int signed_grade, const int execute_grade): _name(name), _signed(false), _signed_grade(signed_grade), _execute_grade(execute_grade)
{
	if (_signed_grade < 0)
		throw(GradeTooHighException());
	else if (_signed_grade > 150)
		throw(GradeTooLowException());
	if (_execute_grade < 0)
		throw(GradeTooHighException());
	else if (_execute_grade > 150)
		throw(GradeTooLowException());
	std::cout << "Constructor of Form called" << std::endl;
}
Form::Form(const Form &other): _name(other._name), _signed(other._signed), _signed_grade(other._signed_grade), _execute_grade(other._execute_grade)
{
	std::cout << "Copy constructor of Form has been called" << std::endl;
}
Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}
Form & Form::operator = (const Form &other)
{
	new (this) Form(other.getName(), other.getSignGrade(), other.getExecuteGrade());
	this->_signed = other._signed;
	return (*this);
}

const std::string Form::getName()const
{
	return(this->_name);
}
const int Form::getSignGrade()const
{
	return(this->_signed_grade);
}
const int Form::getExecuteGrade()const
{
	return(this->_execute_grade);
}
void Form::beSigned(Bureaucrat &bureaucrat)
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

// the following needs to be implemented
// const std::string	_name;
// 		bool				_signed;
// 		const int			_signed_grade;
// 		const int			_execute_grade;
std::ostream & operator<<(std::ostream & o, Form const &form)
{
	o << "Form name: " << form.getName() << "\n";
	o << "Grade of bureucrat to sign: " << form.getSignGrade() << "\n";
	o << "Grade of bureucrat to execute: " << form.getExecuteGrade() << "\n";
	o << "Grade with signature(1 for signed): " << form.checkSignature() << "\n";
	return o;
}

const		bool Form::checkSignature()const
{
	return(this->_signed);
}