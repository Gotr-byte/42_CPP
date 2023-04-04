#include "RobotomyRequestForm.hpp"
# include <sys/time.h>

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm(), _name("RobotomyRequestForm"), _signed(false), _signed_grade(72), _execute_grade(45), _target(target)
{
	std::cout << "Constructor of RobotomyRequestForm of " << target << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): _name(other._name), _signed(other._signed), _signed_grade(other._signed_grade), _execute_grade(other._execute_grade)
{
	std::cout << "Copy constructor of RobotomyRequestForm has been called" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm &other)
{
	new (this) RobotomyRequestForm(other._target);
	this->_signed = other._signed;
	return (*this);
}

const std::string RobotomyRequestForm::getName()const
{
	return(this->_name);
}
<<<<<<< HEAD
int RobotomyRequestForm::getSignGrade()const
{
	return(this->_signed_grade);
}
int RobotomyRequestForm::getExecuteGrade()const
=======
const int RobotomyRequestForm::getSignGrade()const
{
	return(this->_signed_grade);
}
const int RobotomyRequestForm::getExecuteGrade()const
>>>>>>> 7527f8c970c141e7ba1a84c852dd94b0e18e2bab
{
	return(this->_execute_grade);
}

<<<<<<< HEAD
bool RobotomyRequestForm::checkSignature()const
=======
const		bool RobotomyRequestForm::checkSignature()const
>>>>>>> 7527f8c970c141e7ba1a84c852dd94b0e18e2bab
{
	return(this->_signed);
}

std::string RobotomyRequestForm::getTarget ()const
{
	return(this->_target);
}
void RobotomyRequestForm::beSigned(Bureaucrat &bureaucrat)
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

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const &RobotomyRequestForm)
{
	o << RobotomyRequestForm.getName() << "\n";
	o << "Target: " << RobotomyRequestForm.getTarget() << "\n";
	o << "Grade of bureucrat to sign: " << RobotomyRequestForm.getSignGrade() << "\n";
	o << "Grade of bureucrat to execute: " << RobotomyRequestForm.getExecuteGrade() << "\n";
	o << "Grade with signature(1 for signed): " << RobotomyRequestForm.checkSignature() << "\n";
	return o;
}

int	RobotomyRequestForm::generateRandomVal(void) const
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000 + tp.tv_usec / 1000)%100);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(this->checkSignature() && executor.getGrade() < this->getExecuteGrade())
	{
		double random = this->generateRandomVal();
		std::cout << "Roll a d100 die result equals " << random << "\n";
		if (random > 49 )
		{
			std::cout << "Congratulations " << this->getTarget() << " ! Robotomy succeded with 50% chance of failure!" << std::endl;
		}
		else
		{
			std::cout << "Robotomy failed please try again\n";
		}
		
	}
	else if(!this->checkSignature())
	{
		throw (FormNotSignedException());
	}
	else if(executor.getGrade() >= this->getExecuteGrade())
	{
		throw(GradeTooLowException());
	}
}
