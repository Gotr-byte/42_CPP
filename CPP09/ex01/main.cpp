#include "RPN.hpp"

// int ignoreWhitespaces(int i)
// {
  
// }

int main(int argc, char **argv) {
  // std::stack<int> digits;
  // int first_operand;
  // int second_operand;
  // int i;
  //TODO needs output check
  //TODO input check
  RPN rpn;

  rpn.digits.push(argv[1][0] - '0');
  rpn.i = 1;
  while (argv[1][rpn.i])
  {
    if ((argv[1][rpn.i] > '0' && argv[1][rpn.i] <= '9')){
      rpn.digits.push(argv[1][rpn.i] - '0');
    }
    else if (argv[1][rpn.i] == '+')
    {
      rpn.first_operand = rpn.digits.top();
      rpn.digits.pop();
      rpn.second_operand = rpn.digits.top();
      rpn.digits.pop();
      std::cout << rpn.first_operand << " + " << rpn.second_operand << " = " << rpn.first_operand + rpn.second_operand << "\n"; 
      rpn.digits.push(rpn.first_operand + rpn.second_operand);
    }
    else if (argv[1][rpn.i] == '-')
    {
      rpn.first_operand = rpn.digits.top();
      rpn.digits.pop();
      rpn.second_operand = rpn.digits.top();
      rpn.digits.pop();
      std::cout << rpn.first_operand << " - " << rpn.second_operand << " = " << rpn.second_operand - rpn.first_operand << "\n"; 
      rpn.digits.push(rpn.second_operand - rpn.first_operand);
    }
    else if (argv[1][rpn.i] == '*')
    {
      rpn.first_operand = rpn.digits.top();
      rpn.digits.pop();
      rpn.second_operand = rpn.digits.top();
      rpn.digits.pop();
      std::cout << rpn.first_operand << " * " << rpn.second_operand << " = " << rpn.first_operand * rpn.second_operand << "\n"; 
      rpn.digits.push(rpn.first_operand * rpn.second_operand);
    }
    else if (argv[1][rpn.i] == '/')
    {
      rpn.first_operand = rpn.digits.top();
      rpn.digits.pop();
      rpn.second_operand = rpn.digits.top();
      rpn.digits.pop();
      std::cout << rpn.first_operand << " / " << rpn.second_operand << " = " << rpn.second_operand / rpn.first_operand << "\n"; 
      rpn.digits.push(rpn.second_operand / rpn.first_operand);
    }
    rpn.i++;
  }
  return 0;
}