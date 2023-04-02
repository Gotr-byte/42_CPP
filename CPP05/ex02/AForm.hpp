#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm &other);
		AForm & operator = (const AForm &other);

		class		GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Grade to high exception\n");
				}
		};
		class		GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Grade to low exception\n");
				}
		};
		class		FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Form is not signed\n");
				}
		};
		virtual const		bool checkSignature()const;
		virtual void		beSigned(Bureaucrat &bureaucrat) = 0;
		virtual const		std::string getName() const;
		virtual const		int getSignGrade()const;
		virtual const		int getExecuteGrade()const;
		virtual 			void execute(Bureaucrat const & executor) const = 0;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signed_grade;
		const int			_execute_grade;
};

std::ostream & operator<<(std::ostream & o, AForm const &form);