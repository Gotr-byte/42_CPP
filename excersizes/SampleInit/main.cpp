//c++ -Wextra -Werror -Wall ./SampleInit.class.cpp ./main.cpp -o sampleInit
#include <iostream>
#include "SampleInit.class.hpp"

int main (void)
{
	SampleInit instance_one('a', 42, 4.2f );
	SampleInit instance_two('z', 13, 3.14f );

	return 0;
}
