#pragma once
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm;

class RobotomyRequestForm : public AForm
	{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string name);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm & operator = (const RobotomyRequestForm &other);
		std::string	getTarget()const;
		void		beSigned(Bureaucrat &bureaucrat);
		const		std::string getName() const;
		int			getSignGrade()const;
		int			getExecuteGrade()const;
		bool		checkSignature()const;
		void		execute(Bureaucrat const & executor)const;
		int			generateRandomVal(void)const;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signed_grade;
		const int			_execute_grade;
		const std::string	_target;
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const &RobotomyRequestForm);