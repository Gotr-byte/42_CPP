#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

int priceCoinAmmount( std::map<int, double> &myMap, int target, double coinAmmout) {
    std::map<int, double>::iterator it = myMap.upper_bound(target);
    if (it != myMap.begin()) {
        --it; // decrement the iterator to get the closest smaller or equal key
        std::cout << "Closest smaller or equal key: " << it->first << ":" << target << " | " << coinAmmout << " | " << it->second << std::endl;
    } else {
        std::cout << "No smaller or equal key found." << std::endl;
    }
    return 0;
}

void printMap(const std::map<int, double>& myMap) {
	std::map<int, double>::const_iterator      it;
	for (it = myMap.begin(); it != myMap.end(); ++it){
		std::cout << "key " << it->first << " holds value " << it->second << "\n";
    }
}

int readDateKey(std::string inputLine)
{
    std::string year = inputLine.substr(0,4);
    std::string month = inputLine.substr(5,2);
    std::string day = inputLine.substr(8,2);
    std::string date = year + month + day;
    int dateKey = atoi(date.c_str());
    return dateKey;
}

double readValuePrice(std::string inputLine) {
    size_t startPos = 11;
    size_t endPos = inputLine.find('\n', startPos);
    std::string priceToCast = inputLine.substr(startPos, endPos - startPos);
    double priceToReturn = atof(priceToCast.c_str());
    return priceToReturn;
}

double readValueCoin(std::string inputLine) {
    size_t startPos = 13;
    size_t endPos = inputLine.find('\n', startPos);
    std::string priceToCast = inputLine.substr(startPos, endPos - startPos);
    //TODO should throw error if invalid input with reasons
    double priceToReturn = atof(priceToCast.c_str());
    return priceToReturn;
}

int main (int argc, char** argv)
{

	if (argc != 2){
		std::cerr << "Error: invalid arguments\n";
		return 1;
	}
    //TODO data.csv has to be checked
	//TODO the first line is not taken into account
    std::string         bitMineLine;
	std::string         bitPriceLine;
    std::map<int, double> priceMap;
	std::map<int, double> coinMap;

    int key;
    double valueToAdd;

    std::ifstream       inputBitMine(argv[1]);
    if (!inputBitMine){
        std::cout << "Bit mine file does not open" << std::endl;
        return 2;
    }
	std::ifstream       inputBitStock("data.csv");
    if (!inputBitStock){
        std::cout << "Bit stock file does not open" << std::endl;
        return 3;
    }
	while(getline(inputBitMine, bitMineLine)){
		std::cout << bitMineLine << std::endl;
		key = readDateKey(bitMineLine);
		valueToAdd = readValueCoin(bitMineLine);
		std::map<int, double>::iterator iit = coinMap.find(key);
        if (iit != coinMap.end()) {
			 iit->second += valueToAdd;
		} else {
            coinMap[key] += valueToAdd;
        }
	}
    inputBitMine.close();
	while(getline(inputBitStock, bitPriceLine)){
        key = readDateKey(bitPriceLine);
        valueToAdd = readValuePrice(bitPriceLine);
        std::map<int, double>::iterator it = priceMap.find(key);
        if (it != priceMap.end()) {
			//TODO exception at this point
            // std::cout << "Key " << key << "Warning: Price entry already mapped" << it->second << std::endl;
        } else {
            priceMap[key] += valueToAdd;
        }
	}
    inputBitStock.close();

	std::map<int, double>::const_iterator      it;

	for (it = coinMap.begin(); it != coinMap.end(); ++it)
		priceCoinAmmount(priceMap, it->first, it->second);
    //we have a map of dates and prices
}
