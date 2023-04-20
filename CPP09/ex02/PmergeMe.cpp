#include "PmergeMe.hpp"

PmergeMeDequeue::PmergeMeDequeue(){}
PmergeMeDequeue::~PmergeMeDequeue(){}

void PmergeMeDequeue::printVector(){
  for (std::deque<int>::iterator it = this->numbers.begin(); it != this->numbers.end(); ++it) {
        std::cout << *it << " ";
    }
}

void insertionSortFrontToBack(std::deque<int>& arr, int halfPosition, int fullSize) {
    int n = fullSize;
    for (int i = halfPosition; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
    }
}

void PmergeMeDequeue::insertionStrangler() {
    this->numbers.push_back(this->strangler);
    insertionSortFrontToBack(this->numbers, this->numbers.size() - 1, this->numbers.size());
}

void PmergeMeDequeue::insertUnsortedToSorted(){
    int tmpSize = this->numbers.size();
    int halfTmpSize = tmpSize / 2;

    insertionSortFrontToBack(this->numbers, halfTmpSize, tmpSize);
}

void PmergeMeDequeue::insertionSortPairs() {
    int n = this->numbers.size();
    for (int i = 1; i < n; i++) {
        if(i % 2 == 1)
        {
            int keyPair = this->numbers[i - 1];
            int key = this->numbers[i];
            int j = i - 2;
            while (j >= 0 && this->numbers[j] > key) {
                this->numbers[j + 2] = this->numbers[j];
                this->numbers[j + 1] = this->numbers[j - 1];
                j = j - 2;
            }
            this->numbers[j + 1] = keyPair;
            this->numbers[j + 2] = key;
        }
    }
}

void PmergeMeDequeue::shuffleUnsortedPairsToBack(){
    int i = 0;
    int size = this->numbers.size();
    while (i < size)
    {
        if (i % 2 == 0)
        {
            this->numbers.push_back(this->numbers[i]);
        }
        i++;
    }
    i = 0;
    while(i < size/2)
    {
        this->numbers.erase(this->numbers.begin() + i);
        i++;
    }
}

int PmergeMeDequeue::parseAppend(std::string inputString)
{
    char* token = std::strtok(const_cast<char*>(inputString.c_str()), " ");
    while (token != NULL) {
        int n = std::atoi(token);
        if (n < 0 || n > std::numeric_limits<int>::max()){
            std::cerr << "Error: please intput a number in the positvie integer range\n";
            return (2);
        }
        this->numbers.push_back(n);
        token = std::strtok(NULL, " ");
    }
    std::cout << "Before: ";
    printVector();
    std::cout << "\n";
    if (this->numbers.size() % 2)
    {
        this->strangler = this->numbers.back();
        this->isStrangler = 1;
        this->numbers.pop_back();
    }
    for(unsigned int i = 0; i < this->numbers.size(); i++)
    {
        if (i % 2 == 0){}
        else{
            if (this->numbers[i] < this->numbers[i - 1])
                std::swap(this->numbers[i], this->numbers[i - 1]);
        }
    }
    return (0);
}


PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

void PmergeMe::printVector(){
  for (std::vector<int>::iterator it = this->numbers.begin(); it != this->numbers.end(); ++it) {
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
    }
}

void PmergeMe::insertionStrangler() {
    this->numbers.push_back(this->strangler);
    insertionSortFrontToBack(this->numbers, this->numbers.size() - 1, this->numbers.size());
}

void PmergeMe::insertUnsortedToSorted(){
    int tmpSize = this->numbers.size();
    int halfTmpSize = tmpSize / 2;

    insertionSortFrontToBack(this->numbers, halfTmpSize, tmpSize);
}

void PmergeMe::insertionSortPairs() {
    int n = this->numbers.size();
    for (int i = 1; i < n; i++) {
        if(i % 2 == 1)
        {
            int keyPair = this->numbers[i - 1];
            int key = this->numbers[i];
            int j = i - 2;
            while (j >= 0 && this->numbers[j] > key) {
                this->numbers[j + 2] = this->numbers[j];
                this->numbers[j + 1] = this->numbers[j - 1];
                j = j - 2;
            }
            this->numbers[j + 1] = keyPair;
            this->numbers[j + 2] = key;
        }
    }
}

void PmergeMe::shuffleUnsortedPairsToBack(){
    int i = 0;
    int size = this->numbers.size();
    while (i < size)
    {
        if (i % 2 == 0)
        {
            this->numbers.push_back(this->numbers[i]);
        }
        i++;
    }
    i = 0;
    while(i < size/2)
    {
        this->numbers.erase(this->numbers.begin() + i);
        i++;
    }
}

int PmergeMe::parseAppend(std::string inputString)
{
    char* token = std::strtok(const_cast<char*>(inputString.c_str()), " ");
    while (token != NULL) {
        int n = std::atoi(token);
        if (n < 0 || n > std::numeric_limits<int>::max()){
            std::cerr << "Error: please intput a number in the positvie integer range\n";
            return (2);
        }
        this->numbers.push_back(n);
        token = std::strtok(NULL, " ");
    }
    std::cout << "Before: ";
    printVector();
    std::cout << "\n";
    if (this->numbers.size() % 2)
    {
        this->strangler = this->numbers.back();
        this->isStrangler = 1;
        this->numbers.pop_back();
    }
    for(unsigned int i = 0; i < this->numbers.size(); i++)
    {
        if (i % 2 == 0){}
        else{
            if (this->numbers[i] < this->numbers[i - 1])
                std::swap(this->numbers[i], this->numbers[i - 1]);
        }
    }
    return (0);
}
