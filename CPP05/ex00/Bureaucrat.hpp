#pragma once
#include <iostream>
#include <ostream>
#include <stdexcept>

class Bureaucrat;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat & operator = (const Bureaucrat &other);
		
		const 				std::string getName()const;
		int					getGrade()const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		class				GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
					return("Grade to high\n");
		};
		class				GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
					return("Grade to low\n");
		};
	private:
		int					_grade;
		const				std::string _name;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const &bureaucrat);