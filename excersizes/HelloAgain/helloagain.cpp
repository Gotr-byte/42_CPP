// c++ -std=c++98 -Wall -Wextra -Werror helloagain.cpp
#include <iostream>

int main(void)
{
	char	buff[512];

  std::cout << "Hello World!" << std::endl;
  std::cin >> buff;
  std::cout << "You entered [" << buff << "]" << std::endl;

  return 0;	
}