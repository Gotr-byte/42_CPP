#include "Form.hpp"

Form::Form(): _name("Default"), _signed(false), _signed_grade(50), _execute_grade(20)
{
	std::cout << "Constructor of Form called" << std::endl;
}
Form::Form(const std::string name, const int signed_grade, const int execute_grade): _name(name), _signed_grade(signed_grade), _execute_grade(execute_grade)
{
	std::cout << "Constructor of Form called" << std::endl;
}
Form::Form(const Form &other)
{
	new (this) Form(other.getName(), other._signed_grade, other._execute_grade);
	this->_signed = other._signed;
    std::cout << "Copy constructor of Form has been called" << std::endl;
}
Form::~Form(){
    std::cout << "Form destructor called" << std::endl;
}
Form & Form::operator = (const Form &other)
{
	new (this) Form(other.getName(), other._signed_grade, other._execute_grade);
	this->_signed = other._signed;
	return (*this);
}

const std::string Form::getName()const
{
	return(this->_name);
}

void Form::beSigned()
{
	this->_signed = true;
	//TODO get the 
	std::cout << this->getName() << " signed " << this->getName() << std::endl;
}