#include <iostream>
#include <stack>
#include <ctype.h>

int main(int argc, char **argv) {
  std::stack<int> myStack;
  int first_operand;
  int second_operand;
  int i;
  // int result;
  
  myStack.push(argv[1][0] - '0');
  i = 1;
  while (argv[1][i])
  {
    if ((argv[1][i] > '0' && argv[1][i] <= '9')){
      myStack.push(argv[1][i] - '0');
    }
    else if (argv[1][i] == '+')
    {
      first_operand = myStack.top();
      myStack.pop();
      second_operand = myStack.top();
      myStack.pop();
      std::cout << first_operand << " + " << second_operand << " = " << first_operand + second_operand << "\n"; 
      myStack.push(first_operand + second_operand);
    }
    else if (argv[1][i] == '-')
    {
      first_operand = myStack.top();
      myStack.pop();
      second_operand = myStack.top();
      myStack.pop();
      std::cout << first_operand << " - " << second_operand << " = " << second_operand - first_operand << "\n"; 
      myStack.push(second_operand - first_operand);
    }
    else if (argv[1][i] == '*')
    {
      first_operand = myStack.top();
      myStack.pop();
      second_operand = myStack.top();
      myStack.pop();
      std::cout << first_operand << " * " << second_operand << " = " << first_operand * second_operand << "\n"; 
      myStack.push(first_operand * second_operand);
    }
    else if (argv[1][i] == '/')
    {
      first_operand = myStack.top();
      myStack.pop();
      second_operand = myStack.top();
      myStack.pop();
      std::cout << first_operand << " / " << second_operand << " = " << second_operand / first_operand << "\n"; 
      myStack.push(second_operand / first_operand);
    }
    i++;
  }
  return 0;
}