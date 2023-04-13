#include "easyfind.hpp"

int main()
{
    std::list<int>      lst1;
    int toSearch = 17;
    int notFind = 11;

    lst1.push_back(1);
    lst1.push_back(17);
    lst1.push_back(42);

    std::cout << "+++Valid entry test+++\n";
    if(easy_find(lst1, toSearch))
        return(1);
    std::cout << "+++Valid entry test end+++\n\n";
     std::cout << "+++Invalid entry test+++\n";
    if(easy_find(lst1, notFind))
        return(1);
    std::cout << "+++Invalid entry test end+++\n";
}
