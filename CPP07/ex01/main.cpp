// #include "iter.hpp"
#include <iostream>

void print(std::string & a)
{
    std::cout << "Armour type: " << a << "\n";
}

void enchant(std::string & a)
{
    std::cout << "Armour type: " << a + "_enchanted" << "\n";
}

template<typename T>
void iter(T *arrPtr, int len, void (*fun)(T &))
{
    while (len--)
        fun(arrPtr[len]);
}

int main()
{
   
    std::string* armour_types = new std::string[3]; // assign the address of the first element to ptr
    armour_types[0] = "light";
     armour_types[1] = "medium";
      armour_types[2] = "heavy";
    int i  = 3;

    iter(armour_types, i, &print);
     iter(armour_types, i, &enchant);
    delete []armour_types;
}
