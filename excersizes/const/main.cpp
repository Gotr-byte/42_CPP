//c++ -std=c++98 -Wall -Wextra -Werror main.cpp Sample.class.cpp -o const
#include "Sample.class.hpp"
#include <iostream>

int	main(){
	Sample	instance( 3.14f);

	instance.bar();
	return 0;
}