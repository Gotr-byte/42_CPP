#pragma once
#include <iostream>
#include <algorithm>
#include <list>
#include <cstdlib>

class Span
{
    public:
        Span();
        Span(int N);
        Span(const Span &other);
        ~Span();
        Span & operator = (const Span &other);

        void addNumber(int num);
        void addRandNumber();
        int shortestSpan();
        int longestSpan();
        void printVals();
        class				TooManyNumbers : public std::exception
            {
                public:
                    virtual const char* what() const throw()
                    {
                        return("exception: Amount of numbers included in the container is higher than defines\n");
                    }
            };
        class				NotEnoughNumbersToDetermineSpan : public std::exception
            {
                public:
                    virtual const char* what() const throw()
                    {
                        return("exception: Amount of numbers included in the container not enogh to detemine Span\n");
                    }
            };
        int                  _N;
        int                  _addedNumbers;
        std::list<int>       _listSpan;
};
