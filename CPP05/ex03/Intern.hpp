#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class PresidentialPardonForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern & operator = (const Intern &other);
		AForm*		makeForm(std::string name, std::string target);
};