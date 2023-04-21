#pragma once
#include <iostream>
#include <algorithm>
#include <list>


template<typename T>
int easy_find(T intContainer, int integerToCompare){
    typename T::iterator      it;

    it = find(intContainer.begin(), intContainer.end(), integerToCompare);
    if(it == intContainer.end()){
        std::cerr << "integer not found" << "\n";
        return(1);
    }
    else
    {
        std::cout << "The integer value you are searching for equals: " << *it << "\n";
        return 0;
    }
}
