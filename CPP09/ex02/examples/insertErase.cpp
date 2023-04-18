#include <iostream>
#include <vector>

using namespace std;

void printVector(std::vector<int> myVector){
  for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        cout << *it << " ";
    }
}

int main(int argc, char **argv)
{
    // Create an empty list of integers
    std::vector<int> vec;
    int i = 0;

    // Insert elements at the front of the list
    while(argv[1][i])
    {
        vec.push_back(argv[1][i] - '0');
        i++;
    }
    // move the value at index 1 to index 3
    cout << "before insert: ";
    printVector(vec);
    cout << "\n";
    int positionToMove = 0;
    int targetPosition = 3;
    vec.insert(vec.begin()+targetPosition, vec[positionToMove]);  // insert the value at the new position
    vec.erase(vec.begin()+positionToMove);  // remove the value from its current position

    // print the updated vector
    cout << "after insert: ";
    printVector(vec);
    cout << endl;       // output: 1 3 4 2 5

    return 0;
}