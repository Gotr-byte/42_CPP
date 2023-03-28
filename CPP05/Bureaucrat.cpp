#include <iostream>

class Bureaucrat
{
	public:
		std::string getName();
		void setName(std::string name);
	private:
		unsigned char _grade;
		std::string _name;
}