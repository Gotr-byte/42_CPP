#include <iostream>

class Form
{
	public:
		Form();
		Form(const std::string name, const int signed_grade, const int execute_grade);
		~Form();
		Form(const Form &other);
		Form & operator = (const Form &other);

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
		const 		std::string getName();
		void		beSigned();
		const std::string getName() const;
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signed_grade;
		const int			_execute_grade;
};