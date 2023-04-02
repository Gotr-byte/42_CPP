#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm;

class ShrubberyCreationForm : public AForm
	{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string name);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm & operator = (const ShrubberyCreationForm &other);
		std::string	getTarget()const;
		void					beSigned(Bureaucrat &bureaucrat);
		const					std::string getName() const;
		const					int getSignGrade()const;
		const					int getExecuteGrade()const;
		const					bool checkSignature()const;
		void					execute(Bureaucrat const & executor) const;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signed_grade;
		const int			_execute_grade;
		const std::string	_target;
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const &ShrubberyCreationForm);