// c++ mapTarget.cpp -o mapTarget
#include <iostream>
#include <map>

int main() {
    std::map<int, double> myMap;
    myMap[20111201] = 1.0;
    myMap[20111203] = 2.0;
    myMap[20122208] = 3.0;

    int target = 20111205;
    std::map<int, double>::iterator it = myMap.lower_bound(target);
    if (it != myMap.begin()) {
        --it; // decrement the iterator to get the closest smaller key
        std::cout << "Closest smaller key: " << it->first << std::endl;
    } else {
        std::cout << "No smaller key found." << std::endl;
    }
    return 0;
}