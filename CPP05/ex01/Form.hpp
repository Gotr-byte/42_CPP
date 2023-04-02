#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string name, const int signed_grade, const int execute_grade);
		~Form();
		Form(const Form &other);
		Form & operator = (const Form &other);
		void signForm(Form &form);

		class		GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Grade to high\n");
				}
		};
		class		GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Grade to low\n");
				}
		};
		const		bool checkSignature()const;
		void		beSigned(Bureaucrat &bureaucrat);
		const		std::string getName() const;
		const		int getSignGrade()const;
		const		int getExecuteGrade()const;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signed_grade;
		const int			_execute_grade;
};

std::ostream & operator<<(std::ostream & o, Form const &form);