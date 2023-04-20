#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int> myVector){
  for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
}

void insertionSortFrontToBack(std::vector<int>& arr, int halfPosition, int fullSize) {
    int n = fullSize;
    for (int i = halfPosition; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
            std::cout << "\n";
    }
}

void insertionStrangler(std::vector<int>& arr, int  strangler) {
    arr.push_back(strangler);
    insertionSortFrontToBack(arr, arr.size() - 1, arr.size());
}

void insertionSortPairs(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        if(i % 2 == 1)
        {
            int keyPair = arr[i - 1];
            int key = arr[i];
            int j = i - 2;
            while (j >= 0 && arr[j] > key) {
                arr[j + 2] = arr[j];
                arr[j + 1] = arr[j - 1];
                j = j - 2;
            }
            arr[j + 1] = keyPair;
            arr[j + 2] = key;

            std::cout << "\n";
        }
    }
}

void shuffleUnsortedPairsToBack(std::vector<int>& arr){
    int i = 0;
    int size = arr.size();
    while (i < size)
    {
        if (i % 2 == 0)
        {
            arr.push_back(arr[i]);
        }
        i++;
    }
    i = 0;
    while(i < size/2)
    {
        arr.erase(arr.begin() + i);
        i++;
    }
}

void insertUnsortedToSorted(std::vector<int>& arr){
    int i = 0;
    int tmpSize = arr.size();
    int halfTmpSize = tmpSize / 2;

    insertionSortFrontToBack(arr, halfTmpSize, tmpSize);
}

int main(int argc, char** argv) {
    // read the input string from the terminal
    // std::getline(argv[1], inputString);

    std::vector<int> numbers;

    // iterate over the tokens and store the integers in the vector
  
    // print the contents of the vector
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}

int main(int argc, char **argv)
{
    //TODO parsing of unsigned integer values
    //TODO put it all in a class
    //TODO benchmarking using philosopher timestamps
    // Create an empty list of integers
    unsigned int strangler;
    int isStrangler = 0;
    int i = 0;
    std::vector<int> myVector;
    std::string inputString = argv[1];

    char* token = std::strtok(const_cast<char*>(inputString.c_str()), " ");
    while (token != NULL) {
        int n = std::atoi(token);
        myVector.push_back(n);
        token = std::strtok(NULL, " ");
    }
    if (myVector.size() % 2)
    {
        strangler = myVector.back();
        isStrangler = 1;
        myVector.pop_back();
    }
    std::cout << "before swap: ";
    printVector(myVector);
    for(int i = 0; i < myVector.size(); i++)
    {
        if (i % 2 == 0){}
        else{
            if (myVector[i] < myVector[i - 1])
                std::swap(myVector[i], myVector[i - 1]);
        }
    }
    insertionSortPairs(myVector);
    shuffleUnsortedPairsToBack(myVector);
    insertUnsortedToSorted(myVector);
    if (isStrangler){
        insertionStrangler(myVector, strangler);
    }

    std::cout << "\nafter swap: ";
    printVector(myVector);

    return 0;
}