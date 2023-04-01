#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm;

class PresidentialPardonForm : public AForm
	{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string name, const int signed_grade, const int execute_grade);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm & operator = (const PresidentialPardonForm &other);

		// class		GradeTooHighException : public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw()
		// 		{
		// 			return("Grade to high\n");
		// 		}
		// };
		// class		GradeTooLowException : public std::exception
		// {
		// 	public:
		// 		virtual const char* what() const throw()
		// 		{
		// 			return("Grade to low\n");
		// 		}
		// };
		void		beSigned(Bureaucrat &bureaucrat);
		// const		std::string getName() const;
		// const		int getSignGrade()const;
		// const		int getExecuteGrade()const;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signed_grade;
		const int			_execute_grade;
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const &presidentialPardonForm);