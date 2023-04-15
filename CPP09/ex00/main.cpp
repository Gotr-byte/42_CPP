#include "BitcoinExchange.hpp"

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
	std::unordered_map<int, double> coinMap;
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
		key = BitcoinExchange::readDateKey(bitMineLine);
		valueToAdd = BitcoinExchange::readValueCoin(bitMineLine);
		std::unordered_map<int, double>::iterator iit = coinMap.find(key);
        if (iit != coinMap.end()) {
			 iit->second += valueToAdd;
		} else {
            coinMap[key] += valueToAdd;
        }
	}
    inputBitMine.close();
	while(getline(inputBitStock, bitPriceLine)){
        key = BitcoinExchange::readDateKey(bitPriceLine);
        valueToAdd = BitcoinExchange::readValuePrice(bitPriceLine);
        std::map<int, double>::iterator it = priceMap.find(key);
        if (it != priceMap.end()) {
            // std::cout << "Key " << key << "Warning: Price entry already mapped" << it->second << std::endl;
        } else {
            priceMap[key] += valueToAdd;
        }
	}
    inputBitStock.close();

    // BitcoinExchange::printMap(priceMap);
	std::unordered_map<int, double>::const_iterator      it;

	for (it = coinMap.begin(); it != coinMap.end(); ++it)
		BitcoinExchange::priceCoinAmmount(priceMap, it->first, it->second);
    //we have a map of dates and prices
}
