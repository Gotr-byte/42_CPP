#include "ScavTrap.hpp"

int main(){
    ScavTrap lushonda("lushonda");
    ScavTrap alice("alice");

    lushonda.getData();
    lushonda.takeDamage(10);
    lushonda.getData();
    alice.getData();
    alice = lushonda;
    alice.getData();




//
//    for(int i = 0; i < 5; i++)
//    {
//        lushonda.attack("Chandler");
//        lushonda.takeDamage(10);
//    }
//    for(int ii = 0; ii < 12; ii++)
//        lushonda.beRapaired(10);
//    lushonda.takeDamage(300);

    return 0;

}