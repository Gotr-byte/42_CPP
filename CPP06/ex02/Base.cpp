#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base(){}
Base::~Base(){}
Base::Base(const Base& other)
{
    (void)&other;
}
Base & Base::operator = (const Base & other){
    (void)&other;
    return (*this);
}

int	Base::generateRandomVal(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000 + tp.tv_usec / 1000)%100);
}

Base *Base::generate(void){
    int random = Base::generateRandomVal();
    if (random < 33)
    {
        Base *returnPtrA = new A();
        return (returnPtrA);
    }
    else if (random >= 33 && random < 67 )
    {
        Base *returnPtrB = new B();
        return (returnPtrB);
    }
    else
    {
        Base *returnPtrC = new C();
        return (returnPtrC);
    }
    return(NULL);
}
    //  Child1 *c = dynamic_cast<Child1 *>(b);
    // if (c == NULL)
    // {
    //     std::cout << "Conversion is  NOT Ok" <<  std::endl;
    // }
    // else
    // {
    //     std::cout << "Conversion is Ok" << std::endl;
    // }
void Base::identify(Base* p){
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
void Base::identify(Base& p){
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