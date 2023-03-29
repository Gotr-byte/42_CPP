#include <iostream>
#include <ostream>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat & operator = (const Bureaucrat &other);
		std::string getName()const;
		int getGrade()const;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Grade to high\n");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Grade to low\n");
				}
		};
		void setGrade(int grade);
		void setName(std::string name);
		void incrementGrade();
		void decrementGrade();
	private:
		unsigned char _grade;
		std::string _name;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const &Bureaucrat);