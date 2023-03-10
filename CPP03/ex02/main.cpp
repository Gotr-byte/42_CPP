#include "FragTrap.hpp"

int main(){
    FragTrap lushonda("joe");

    lushonda.highFiveGuys();
    for(int i = 0; i < 5; i++)
    {
        lushonda.attack("Chandler");
        lushonda.takeDamage(10);
    }
    for(int ii = 0; ii < 12; ii++)
        lushonda.beRapaired(10);
    lushonda.takeDamage(300);

    return 0;

}