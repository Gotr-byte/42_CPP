#include <iostream>
#include <set>

int main()
{
    // Define a set of integers
    std::set<int> mySet;

    // Insert some values into the set
    mySet.insert(3);
    mySet.insert(2);
    mySet.insert(1);

    // Print the contents of the set
    std::cout << "Set contains:";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';

    // Check if a value is in the set
    if (mySet.count(2)) {
        std::cout << "2 is in the set\n";
    } else {
        std::cout << "2 is not in the set\n";
    }

    // Remove a value from the set
    mySet.erase(3);

    // Print the contents of the set again
    std::cout << "Set contains:";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';

    return 0;
}