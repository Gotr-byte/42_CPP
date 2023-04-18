#include <iostream>
#include <vector>

using namespace std;

void printVector(std::vector<int> myVector){
  for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); ++it) {
        std::cout << *it << " ";
    }
}

void insertionSortPairs(vector<int>& arr) {
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
            printVector(arr);
            std::cout << "\n";
        }
    }
}

int main(int argc, char **argv)
{
    // Create an empty list of integers
    std::vector<int> arr;
    int i = 0;

    // Insert elements at the front of the list
    while(argv[1][i])
    {
        arr.push_back(argv[1][i] - '0');
        i++;
    }

    // sort the array using insertion sort
    insertionSort(arr);

    // print the sorted array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;   // output: 1 2 3 4 5 6

    return 0;
}