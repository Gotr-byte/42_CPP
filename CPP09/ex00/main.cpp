#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

//date validator

int readDateKey(std::string inputLine)
{
    // std::string inputLine = "2022-11-12, 23.3";

    std::string year = inputLine.substr(0,4);
    std::string month = inputLine.substr(5,2);
    std::string day = inputLine.substr(8,2);
    std::string date = year + month + day;
    int dateKey = atoi(date.c_str());
    // std::cout << "the date in integer equals: " << dateKey << "\n";
    return dateKey;
}

double readValuePrice(std::string inputLine) {
    //  std::string inputLine = "2022-11-12,123567623.37";

    // Find the position of the first newline character after position 11
    size_t startPos = 11;
    size_t endPos = inputLine.find('\n', startPos);

    // Extract the substring from startPos up to (but not including) the newline character
    std::string priceToCast = inputLine.substr(startPos, endPos - startPos - 15);
    
    // std::cout << "Substring: " << priceToCast << std::endl;
    double priceToReturn = atof(priceToCast.c_str());
    return priceToReturn;
}

//input a filename and two strings
int main ()
{

    //TODO data.csv has to be checked
    // std::string         bitMineLine;
	std::string         bitPriceLine;
    std::map<int, double> priceMap;

    int key;
    double valueToAdd;

    // std::ifstream       inputBitMine("bitMine.csv");
    // if (!inputBitMine){
    //     std::cout << "Bit mine file does not open" << std::endl;
    //     return 2;
    // }
	std::ifstream       inputBitStock("data.csv");
    // if (!inputBitMine){
    //     std::cout << "Bit stock file does not open" << std::endl;
    //     return 3;
    // }
	// while(getline(inputBitMine, bitMineLine)){
	// 	std::cout << bitMineLine << std::endl;
 
	// }
    // inputBitMine.close();
	while(getline(inputBitStock, bitPriceLine)){
		std::cout << bitPriceLine << std::endl;
        key = readDateKey(bitPriceLine);
        valueToAdd = readValuePrice(bitPriceLine);
        std::cout << "Read date key: " << key << "\n";
        std::cout << "Read value of price: " << valueToAdd << "\n";
        std::map<int, double>::iterator it = priceMap.find(key);
        if (it != priceMap.end()) {
            std::cout << "Key " << key << "Warning: Price entry already mapped" << it->second << std::endl;
        } else {
            priceMap[key] += valueToAdd;
            std::cout << "New Key " << key << " has value price " << priceMap[key] << std::endl;
        }
	}
    inputBitStock.close();
    //we have a map of dates and prices
}
