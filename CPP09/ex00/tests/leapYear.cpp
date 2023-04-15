// little code to check map validity works friom 9999BC to AD9999
#include <iostream>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int year = atoi(argv[1]);
	int month = atoi(argv[2]);
	int day = atoi(argv[3]);
	int leap = -1;

	if(!(year % 4) && (year%100) || !(year % 400))
		leap = 1;
	else
		leap = 0;

	if (month < 1 || month > 12)
		std::cout << "month not ok\n";
	else if(month == 2)
	{
		if(leap && day > 29 ||(!leap && day > 28)||(!leap && day > 28))
			std::cout << "day not ok" << "\n";
		else
			std::cout << "day is ok" << "\n";
	}
	else if (month % 2)
	{
		if (day > 31 || day < 1)
			std::cout << "day not ok" << "\n";
		else
			std::cout << "day is ok" << "\n";
	}
	else if (!(month % 2))
	{
		if (day > 30 || day < 1)
			std::cout << "day not ok" << "\n";
		else
			std::cout << "day is ok" << "\n";
	}
	std::cout << "1 for leap " << leap << "\n";
}