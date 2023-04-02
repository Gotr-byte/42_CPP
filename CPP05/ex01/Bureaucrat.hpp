#pragma once
#include <iostream>
#include <ostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat & operator = (const Bureaucrat &other);
		Bureaucrat(const std::string name);
		
		const std::string	getName()const;
		int					getGrade()const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &form);
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
