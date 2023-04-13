#pragma once
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){}
        ~MutantStack(){}
        MutantStack (const MutantStack &other){
            if(this!=&other)
            {
                *this = other;
            }
        }
        MutantStack  & operator = (const MutantStack &other){
            if(this!=&other)
            {
                *this = other;
            }
            return *this;
        }
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        };
        iterator end()
        {
            return this->c.end();
        };
};
