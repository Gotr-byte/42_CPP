#include <iostream>
#include <map>
#include <cstdlib>

int main(int argc, char **argv)
{
    std::map<int, double> myMap;

    int key = atoi(argv[1]);
    double valueToAdd = atof(argv[2]);
    std::map<int, double>::iterator it = myMap.find(key);
    if (it != myMap.end()) {
        std::cout << "Key " << key << "Warning: Price entry already mapped" << it->second << std::endl;
    } else {
        myMap[key] += valueToAdd;
        std::cout << "New Key " << key << " has value price" << myMap[key] << std::endl;
    }
    return 0;
}