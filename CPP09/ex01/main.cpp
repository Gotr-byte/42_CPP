#include "RPN.hpp"

int invalid_input_check(char **argv, RPN &rpn)
{
  int i = 0;
  int operand_number = 0;
  while (argv[1][i])
  {
    if ((argv[1][i] > '0' && argv[1][i] <= '9')){
      operand_number++;
    }
    else if (argv[1][i] == '+'){
      rpn.operator_number++;
    }
    else if (argv[1][i] == '-'){
      rpn.operator_number++;
    }
    else if (argv[1][i] == '*'){
      rpn.operator_number++;
    }
    else if (argv[1][i] == '/'){
      rpn.operator_number++;
    }
    else if (argv[1][i] == ' ' || argv[1][i] == ' '){}
    else{
      std::cerr << "Error: invalid entry\n";
      return(1);
    }
    i++;
  }
  if (operand_number != rpn.operator_number + 1){
    std::cerr << "Error: invalid number of operators and operands\n";
    return(2);
  }

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 2){
    std::cerr << "Error: invalid number of arguments\n";
    return(3);
  }
  else{
    RPN rpn;
    rpn.digits.push(argv[1][0] - '0');
    rpn.i = 1;
    rpn.operator_number = 0;
    if(invalid_input_check(argv, rpn)){
      return(4);
    }
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
        rpn.operator_number--;
        if (rpn.operator_number <= 0)
          std::cout << rpn.first_operand + rpn.second_operand << "\n";
        rpn.digits.push(rpn.first_operand + rpn.second_operand);
      }
      else if (argv[1][rpn.i] == '-')
      {
        rpn.first_operand = rpn.digits.top();
        rpn.digits.pop();
        rpn.second_operand = rpn.digits.top();
        rpn.digits.pop();
        rpn.operator_number--;
        if (rpn.operator_number <= 0)
          std::cout << rpn.second_operand - rpn.first_operand << "\n"; 
        rpn.digits.push(rpn.second_operand - rpn.first_operand);
      }
      else if (argv[1][rpn.i] == '*')
      {
        rpn.first_operand = rpn.digits.top();
        rpn.digits.pop();
        rpn.second_operand = rpn.digits.top();
        rpn.digits.pop();
        rpn.operator_number--;
        if (rpn.operator_number <= 0)
          std::cout << rpn.first_operand * rpn.second_operand << "\n";
        rpn.digits.push(rpn.first_operand * rpn.second_operand);
      }
      else if (argv[1][rpn.i] == '/')
      {
        rpn.first_operand = rpn.digits.top();
        rpn.digits.pop();
        rpn.second_operand = rpn.digits.top();
        rpn.digits.pop();
        rpn.operator_number--;
        if (rpn.operator_number <= 0)
          std::cout << rpn.second_operand / rpn.first_operand << "\n";
        rpn.digits.push(rpn.second_operand / rpn.first_operand);
      }
      rpn.i++;
    }
  }
  return 0;
}