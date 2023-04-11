#pragma once
#include <iostream>
#include <algorithm>
#include <list>


template<typename T>
int easy_find(T intContainer, int integerToCompare){
    typename T::const_iterator      it;
    typename T::const_iterator      ite = intContainer.end();
    
    for (it = intContainer.begin(); it != ite; ++it)
    {
        if (*it == integerToCompare)
        {
            std::cout << "The integer value you are searching for equals: " << *it << "\n";
            return 0;
        }
    }
    std::cerr << "integer not found" << "\n";
    return(1);
}
