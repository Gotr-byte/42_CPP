#pragma once
#include <iostream>
#include <ostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat & operator = (const Bureaucrat &other);
		Bureaucrat(const std::string name, int grade);
		
		const std::string	getName()const;
		int					getGrade()const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm &form);
		class				GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Grade to high\n");
				}
		};
		class				GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Grade to low\n");
				}
		};
	
	private:
		int		_grade;
		const	std::string _name;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const &bureaucrat);
