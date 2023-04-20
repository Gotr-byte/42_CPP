#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();
        std::vector<int>    numbers;
        int                 isStrangler;
        unsigned int        strangler;
        void                printVector();
        int                 parseAppend(std::string inputString);
        void                insertionSortPairs();
        void                shuffleUnsortedPairsToBack();
        void                insertUnsortedToSorted();
        void                insertionStrangler();
    private:
        PmergeMe(const PmergeMe &other);
        PmergeMe & operator = (const PmergeMe &other);
      
};

class PmergeMeDequeue
{
    public:
        PmergeMeDequeue();
        ~PmergeMeDequeue();
        std::deque<int>    numbers;
        int                 isStrangler;
        unsigned int        strangler;
        void                printVector();
        int                 parseAppend(std::string inputString);
        void                insertionSortPairs();
        void                shuffleUnsortedPairsToBack();
        void                insertUnsortedToSorted();
        void                insertionStrangler();
    private:
        PmergeMeDequeue(const PmergeMe &other);
        PmergeMeDequeue & operator = (const PmergeMe &other);
      
};