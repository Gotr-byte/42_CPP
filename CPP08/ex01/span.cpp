#include "span.hpp"

Span::Span():_N(0), _addedNumbers(0){}
Span::Span(int N): _N(N), _addedNumbers(0){
}
Span::Span(const Span &other){
    if (this != &other){
        this->_N = other._N;
        this->_addedNumbers = other._addedNumbers;
        this->_listSpan = other._listSpan;
    }
}
Span::~Span(){}
Span & Span::operator = (const Span &other){
       if (this != &other){
        this->_N = other._N;
        this->_addedNumbers = other._addedNumbers;
        this->_listSpan = other._listSpan;
    }
    return *this;
}

void Span::addNumber(int num){
    if (this->_addedNumbers >= this->_N)
        throw(TooManyNumbers());
    this->_listSpan.push_back(num);
    this->_addedNumbers = this->_addedNumbers + 1;
}

void Span::addRandNumber(){
    if (this->_addedNumbers >= this->_N)
        throw(TooManyNumbers());
        
    int random_num = rand() % 10000;
    this->_listSpan.push_back(random_num);
    this->_addedNumbers = this->_addedNumbers + 1;
}

int Span::longestSpan()
{
    if (this->_addedNumbers < 2)
        throw(NotEnoughNumbersToDetermineSpan());
    std::list<int>::const_iterator      it;
    std::list<int>::const_iterator      ite = this->_listSpan.end();
    std::list<int>::const_iterator      iit;
    std::list<int>::const_iterator      iite = this->_listSpan.end();
    int tmpSpan = -1;
    int highSpan;
    int gate = 1;
    
    for (it = this->_listSpan.begin(); it != ite; ++it)
    {
        for (iit = this->_listSpan.begin(); iit != iite; ++iit)
        {
            if(it != iit)
            {
                tmpSpan = *it - *iit;
                if (tmpSpan < 0)
                    tmpSpan = -tmpSpan;
                if (gate == 1)
                {
                    highSpan = tmpSpan;
                    gate = 0;
                }
                if (tmpSpan > highSpan)
                    highSpan = tmpSpan;
            }
        }
    }
    return (highSpan);
}

int Span::shortestSpan(){
    if (this->_addedNumbers < 2)
        throw(NotEnoughNumbersToDetermineSpan());
    std::list<int>::const_iterator      it;
    std::list<int>::const_iterator      ite = this->_listSpan.end();
    std::list<int>::const_iterator      iit;
    std::list<int>::const_iterator      iite = this->_listSpan.end();
    int tmpSpan = -1;
    int lowSpan;
    int gate = 1;
    
    for (it = this->_listSpan.begin(); it != ite; ++it)
    {
        for (iit = this->_listSpan.begin(); iit != iite; ++iit)
        {
            if(it != iit)
            {
                tmpSpan = *it - *iit;
                if (tmpSpan < 0)
                    tmpSpan = -tmpSpan;
                if (gate == 1)
                {
                    lowSpan = tmpSpan;
                    gate = 0;
                }
                if (tmpSpan < lowSpan)
                    lowSpan = tmpSpan;
            }
        }
    }
    return(lowSpan);
}
