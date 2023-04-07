#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <unistd.h>


int	generateRandomVal(void)
{
	struct timeval	tp;

    usleep(50000);
	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000 + tp.tv_usec / 1000)%100);
}

Base *generate(void){
    int random = generateRandomVal();

    if (random < 34)
    {
        std::cout << "Class A generated\n";
        Base *returnPtrA = new A();
        return (returnPtrA);
    }
    else if (random >= 34 && random < 67 )
    {
        std::cout << "Class B generated\n";
        Base *returnPtrB = new B();
        return (returnPtrB);
    }
    else
    {
        std::cout << "Class C generated\n";
        Base *returnPtrC = new C();
        return (returnPtrC);
    }
    return(NULL);
}

void identify(Base* p){
    A *isA = dynamic_cast<A *>(p);
    if (isA == NULL)
    {
        std::cout << "it is not A" <<  std::endl;
    }
    else
    {
        std::cout << "it is A" << std::endl;
        return ;
    }
    B *isB = dynamic_cast<B *>(p);
    if (isB == NULL)
    {
        std::cout << "it is not B" <<  std::endl;
    }
    else
    {
        std::cout << "it is B" << std::endl;
        return ;
    }
    C *isC = dynamic_cast<C *>(p);
    if (isC == NULL)
    {
        std::cout << "it is not C" <<  std::endl;
    }
    else
    {
        std::cout << "it is C" << std::endl;
        return ;
    }

}

//   try {
//         Child2 &    d   = dynamic_cast<Child2 &>(*b);
//         std::cout << "Conversion is Ok" << std::endl;
//     }
//     catch(std::bad_cast &bc)
//     {
//         std::cout << "Conversion is Not Ok: " << bc.what() << std::endl;
//         return 0;
//     }
void identify(Base& p){
    try {
        A &    isA   = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(std::bad_cast &bc)
    {
        std::cout << "not A " << bc.what() << std::endl;
    }
    try {
        B &    isB   = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(std::bad_cast &bc)
    {
        std::cout << "not B " << bc.what() << std::endl;
    }
    try {
        C &    isC   = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(std::bad_cast &bc)
    {
        std::cout << "not C " << bc.what() << std::endl;
    }
}


int main()
{
    std::cout << "+++Weclome to the class generator and identifier+++\n";
    int i = 0;
    while (i < 3)
    {
        Base* basePtr = generate();
        Base& ace = *basePtr;
        std::cout << "+++class generated+++\n";
        identify(basePtr);
        std::cout << "+++performed test by pointer number: [" << i << "] +++\n";
        identify(ace);
        std::cout << "+++performed test by reference number: [" << i << "] +++\n";
        i++;
        delete basePtr;
        std::cout << "+++freed memory+++\n";
    }
}
