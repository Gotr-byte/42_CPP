#include "Sample.class.hpp"
#include <iostream>

int main(void)
{
	Sample instance;

	instance.publicFoo = 42;
	std::cout << "instance.publicFoo " << instance.publicFoo << std::endl;
	instance._privateFoo = 42;
	std::cout << "instance._priveteFoo" << instance._privateFoo << std::endl;
	instance.publicBar()
}