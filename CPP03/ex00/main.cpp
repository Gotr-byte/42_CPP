#include "ClapTrap.hpp"

int main(){
    ClapTrap    joe("Joe");
    for(int i = 0; i < 5; i++)
    {
        joe.attack("Chandler");
        joe.takeDamage(1);
    }
    for(int ii = 0; ii < 12; ii++)
        joe.beRapaired(10);
    joe.takeDamage(100);

}