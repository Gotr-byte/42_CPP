#include "BitcoinExchange.hpp"

    // BitcoinExchange::BitcoinExchange(){}
    // BitcoinExchange::BitcoinExchange(const BitcoinExchange &other){
    //     //TODO
    // }
    // BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange &other){
    //     //TODO
    // }
    // BitcoinExchange::~BitcoinExchange(){}

    int BitcoinExchange::priceCoinAmmount(std::map<int, double> &myMap, int target, double coinAmmout) {
    std::map<int, double>::iterator it = myMap.upper_bound(target);
    if (it != myMap.begin()) {
        --it; // decrement the iterator to get the closest smaller or equal key
        std::cout << "Closest smaller or equal key: " << it->first << ":" << target << " | " << coinAmmout << " | " << it->second << std::endl;
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

int BitcoinExchange::readDateKey(std::string inputLine)
{
    std::string year = inputLine.substr(0,4);
    std::string month = inputLine.substr(5,2);
    std::string day = inputLine.substr(8,2);
    std::string date = year + month + day;
    int dateKey = atoi(date.c_str());
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
    //TODO should throw error if invalid input with reasons
    double priceToReturn = atof(priceToCast.c_str());
    return priceToReturn;
}