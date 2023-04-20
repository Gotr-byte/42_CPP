#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv)
{
    //TODO make class templates
    //TODO make deque template
    // Create an empty list of integers
    if(argc != 2){
        std::cerr << "Invalid number of arguments\n";
        return 1;
    }
    else{
        PmergeMe numbersVector;
        PmergeMeDequeue numbersDequeue;

        numbersVector.isStrangler = 0;

        std::clock_t start = std::clock();
        if(numbersVector.parseAppend(argv[1]))
            return 1;
        numbersVector.insertionSortPairs();
        numbersVector.shuffleUnsortedPairsToBack();
        numbersVector.insertUnsortedToSorted();
        if (numbersVector.isStrangler){
            numbersVector.insertionStrangler();
        }
        // get the elapsed time in microseconds
        std::clock_t end = std::clock();
        double elapsed_time = (end - start) / (double)CLOCKS_PER_SEC * 1000000;
        std::cout << "After: ";
        numbersVector.printVector();
        std::cout << "\n";
        // output the elapsed time

        numbersDequeue.isStrangler = 0;

        std::clock_t start2 = std::clock();
        if(numbersDequeue.parseAppend(argv[1]))
            return 1;
        numbersDequeue.insertionSortPairs();
        numbersDequeue.shuffleUnsortedPairsToBack();
        numbersDequeue.insertUnsortedToSorted();
        if (numbersDequeue.isStrangler){
            numbersDequeue.insertionStrangler();
        }
        // get the elapsed time in microseconds
        std::clock_t end2 = std::clock();
        double elapsed_time2 = (end2 - start2) / (double)CLOCKS_PER_SEC * 1000000;
        std::cout << "After: ";
        numbersDequeue.printVector();
        std::cout << "\n";
        // output the elapsed time
        std::cout << "Time to process a range of: " << numbersVector.numbers.size() << " elements with STD::Vector : " << elapsed_time << " microseconds" << std::endl;
        std::cout << "Time to process a range of: " << numbersDequeue.numbers.size() << " elements with STD::Dequeue : " << elapsed_time2 << " microseconds" << std::endl;
    }
    return 0;
}
