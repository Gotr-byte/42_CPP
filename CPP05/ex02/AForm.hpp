#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string name, const int signed_grade, const int execute_grade);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm & operator = (const AForm &other);

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
		virtual void		beSigned(Bureaucrat &bureaucrat) = 0;
		virtual const		std::string getName() const;
		virtual const		int getSignGrade()const;
		virtual const		int getExecuteGrade()const;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signed_grade;
		const int			_execute_grade;
};

std::ostream & operator<<(std::ostream & o, AForm const &form);