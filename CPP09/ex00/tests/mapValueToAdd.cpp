// c++ mapValueToAdd.cpp -o mapValueToAdd
#include <iostream>
#include <map>
#include <cstdlib>

//enter int date YYYYMMDD and double value
int main(int argc, char **argv) {
    std::map<int, double> myMap;
    myMap[20110321] = 2;
    myMap[20110323] = 3;
    myMap[21110101] = 4;

    int key = atoi(argv[1]);
    double valueToAdd = atof(argv[2]);
    std::map<int, double>::iterator it = myMap.find(key);
    if (it != myMap.end()) {
        it->second += valueToAdd; // Add the value to the existing key
        std::cout << "Key " << key << " found with updated value " << it->second << std::endl;
    } else {
        std::cout << "Key " << key << " not found." << std::endl;
        myMap[key] += valueToAdd;
        std::cout << "New Key " << key << " has value " << myMap[key] << std::endl;
    }
    return 0;
}