#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    this->_grade = -1;
	this->_name = "default";
	std::cout << "Constructor of bureaucrat called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other){
    if (this != &other) {
        this->_grade = other._grade;
		this->_name = other._name;
    }
    std::cout << "Copy constructor of bureaucrat has been called" << std::endl;
}
Bureaucrat::~Bureaucrat(){
    std::cout << "Bureaucrat destructor called" << std::endl;
}
Bureaucrat & Bureaucrat::operator = (const Bureaucrat &other){

    if (this != &other) {
        this->_grade = other._grade;
		this->_name = other._name;
    }
    return *this;
}

std::string Bureaucrat::getName()const
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
		std::cout << "succesfully set grade to " << grade << std::endl;
	}
}

void Bureaucrat::setName(std::string name)
{
	this->_name = name;
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
