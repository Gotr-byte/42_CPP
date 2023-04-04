#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}
Bureaucrat::Bureaucrat(const std::string name, int grade): _grade(grade), _name(name)
{
	std::cout << "Constructor of bureaucrat called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other): _grade(other.getGrade()), _name(other.getName())
{
    std::cout << "Copy constructor of bureaucrat has been called" << std::endl;
}
Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
}
Bureaucrat & Bureaucrat::operator = (const Bureaucrat &other)
{
	if(this != &other)
		this->_grade = other._grade;
	return (*this);
}

const std::string Bureaucrat::getName()const
{
	return(this->_name);
}

int Bureaucrat::getGrade()const
{
	return(this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 0)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
	else
	{
		this->_grade = grade;
		std::cout << "succesfully set " << this->_name << " grade to " << grade << std::endl;
	}
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 0)
		throw(GradeTooHighException());
	this->_grade = this->_grade - 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw(GradeTooLowException());
	this->_grade = this->_grade + 1;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat){
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "\n";
    return o;
}

void Bureaucrat::signForm(AForm &form)
{
	if (form.checkSignature())
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because his grade was too low." << std::endl;

}

void	Bureaucrat::executeForm(AForm const & form)
{
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName();
}