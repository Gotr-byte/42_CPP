#include "Base.hpp"
#include "A.hpp"

int main()
{
    std::cout << "+++Weclome to the class generator and identifier+++\n";
    int i = 0;
    // std::cout << "Perform test of pointer"
    while (i < 3)
    {
        Base* basePtr = Base::generate();
        Base& ace = *basePtr;
        std::cout << "+++class generated+++\n";
        Base::identify(basePtr);
        std::cout << "+++performed test by pointer number: [" << i << "] +++\n";
        Base::identify(ace);
        std::cout << "+++performed test by reference number: [" << i << "] +++\n";
        i++;
        delete basePtr;
        std::cout << "+++freed memory+++\n";
    }
}