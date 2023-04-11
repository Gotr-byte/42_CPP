#include "span.hpp"

Span::Span(int N): _N(N), _addedNumbers(0){
}
Span::Span(const Span &other){
    if (this != &other){
        this->_N = other._N;
        this->_addedNumbers = other._addedNumbers;
        this->_listSpan = other._listSpan;
        this->_lowestValue = other._lowestValue;
        this->_highestValue = other._highestValue;
    }
}
Span::~Span(){}
Span & Span::operator = (const Span &other){
       if (this != &other){
        this->_N = other._N;
        this->_addedNumbers = other._addedNumbers;
        this->_listSpan = other._listSpan;
        this->_lowestValue = other._lowestValue;
        this->_highestValue = other._highestValue;
    }
    return *this;
}

void Span::addNumber(){
    if (this->_addedNumbers >= this->_N)
        throw(TooManyNumbers());
        
    int random_num = rand() % 10000;
    if (this->_addedNumbers == 0)
    {
        this->_lowestValue = random_num;
        this->_highestValue = random_num;
    }
    if (random_num > _highestValue)
        this->_highestValue = random_num;
    if (random_num < _lowestValue)
        this->_lowestValue = random_num;
    this->_listSpan.push_back(random_num);
    this->_addedNumbers = this->_addedNumbers + 1;
}

void Span::longestSpan()
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
    std::cout << "highSpan equals: " << highSpan << "\n";
}

void Span::shortestSpan(){
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
    std::cout << "lowSpan equals: " << lowSpan << "\n";
}
