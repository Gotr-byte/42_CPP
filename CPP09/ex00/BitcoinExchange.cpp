#include "BitcoinExchange.hpp"

    BitcoinExchange::BitcoinExchange(){}
    BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
        //TODO
    }
    BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange &other){
        //TODO
		return *this;
    }
    BitcoinExchange::~BitcoinExchange(){}


	void printMonth(int month)
	{
		if (month < 10)
			std::cout << 0 << month;
		else
			std::cout << month;
	}

	void printDay(int day)
	{
		if (day < 10)
			std::cout << 0 << day;
		else
			std::cout << day;
	}

	void printYear(int year)
	{
		if (year < 10)
			std::cout << 000 << year;
		else if(year < 100)
			std::cout << 00 << year;
		else if(year < 1000)
			std::cout << 0 << year;
		else
			std::cout << year;
	}


//expected output  2011-01-03 => 3 = 0.9
    int BitcoinExchange::priceCoinAmmount(std::map<int, double> &myMap, int target, double coinAmount) {
    std::map<int, double>::iterator it = myMap.upper_bound(target);
    if (it != myMap.begin()) {
        --it; // decrement the iterator to get the closest smaller or equal key
        printYear(target / 10000);
		std::cout << "-";
		printMonth((target % 10000) / 100);
		std::cout << "-";
		printDay(target % 100);
		std::cout << " => " << coinAmount << " = " << it->second * coinAmount<< std::endl;
    } else {
        std::cout << "No smaller or equal key found." << std::endl;
    }
    return 0;
}

void BitcoinExchange::printMap(const std::map<int, double>& myMap) {
	std::map<int, double>::const_iterator      it;
	for (it = myMap.begin(); it != myMap.end(); ++it){
		std::cout << "key " << it->first << " holds value " << it->second << "\n";
    }
}

bool BitcoinExchange::checkNum(std::string checkedInput)
{
	for(int i = 0; checkedInput[i] && checkedInput[i] != '\n'; i++){
		if (!(isnumber(checkedInput[i])))
		{
			return (false);
		}
	}
	return(true);
}

bool BitcoinExchange::checkNumFloat(std::string checkedInput)
{
	int i ;
	for(i = 0; checkedInput[i] && checkedInput[i] != '\n' && checkedInput[i] != '.'; i++){
		if (!(isnumber(checkedInput[i])))
		{
			return (false);
		}
	}
	i++;
	while( checkedInput[i] && checkedInput[i] != '\n'){
		if (!(isnumber(checkedInput[i])))
		{
			return (false);
		}
		i++;
	}
	return(true);
}

int BitcoinExchange::readDateKey(std::string inputLine)
{
    std::string year = inputLine.substr(0,4);
	if(!checkNum(year))
		throw(InvalidFormat());
    std::string month = inputLine.substr(5,2);
	if(!checkNum(month))
		throw(InvalidFormat());
    std::string day = inputLine.substr(8,2);
	if(!checkNum(day))
		throw(InvalidFormat());
    std::string date = year + month + day;
    int dateKey = atoi(date.c_str());
	if(!(BitcoinExchange::dateValid(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str())))){
		throw(InvalidDateException());
	}
    return dateKey;
}

double BitcoinExchange::readValuePrice(std::string inputLine) {
    size_t startPos = 11;
    size_t endPos = inputLine.find('\n', startPos);
    std::string priceToCast = inputLine.substr(startPos, endPos - startPos);
    double priceToReturn = atof(priceToCast.c_str());
    return priceToReturn;
}

double BitcoinExchange::readValueCoin(std::string inputLine) {
    size_t startPos = 13;
    size_t endPos = inputLine.find('\n', startPos);
    std::string priceToCast = inputLine.substr(startPos, endPos - startPos);
	if (inputLine.substr(10, 3) != " | ")
		throw(InvalidFormat());
	if(!checkNumFloat(priceToCast))
		throw(InvalidFormat());
    //TODO should throw error if invalid input with reasons
    double priceToReturn = atof(priceToCast.c_str());
	if (priceToReturn < 0)
		throw(BitValueTooLow());
	if (priceToReturn > 1000)
		throw(BitValueTooHigh());
    return priceToReturn;
}

bool BitcoinExchange::dateValid(int year, int month, int day)
{
    bool dateValidity = 0;
	int leap = -1;
	if((!(year % 4) && (year%100)) || !(year % 400))
		leap = 1;
	else
		leap = 0;
	if (month < 1 || month > 12){
		return (dateValidity);
	}
	else if(month == 2)
	{
		if((leap && day > 29) || (!leap && day > 28)){
			return(dateValidity);
		}
		else
			dateValidity = 1;
	}
	else if (((month < 8) && (month % 2)) || ((month >= 8) && !(month % 2)))
	{
		if (day > 31 || day < 1){
			return(dateValidity);
		}
		else
			dateValidity = 1;
	}
	else if (((month < 8) && (!(month % 2))) || ((month >= 8) && (month % 2)))
	{
		if (day > 30 || day < 1){
			return(dateValidity);
		}
		else
			dateValidity = 1;
	}
	return(dateValidity);
}
