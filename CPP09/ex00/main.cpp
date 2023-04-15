#include "BitcoinExchange.hpp"

int main (int argc, char** argv)
{
	if (argc != 2){
		std::cerr << "Error: invalid arguments\n";
		return 1;
	}
    //TODO data.csv has to be checked
	//TODO the first line is not taken into account
    BitcoinExchange bitcoinExchange;
    std::string         bitMineLine;
	std::string         bitPriceLine;
    std::map<int, double> priceMap;
    int key;
    double valueToAdd;
    double coinAmmount;

    std::ifstream       inputBitMine(argv[1]);
    if (!inputBitMine){
        std::cout << "Error: bit mine file does not open" << std::endl;
        return 2;
    }
	std::ifstream       inputBitStock("data.csv");
    if (!inputBitStock){
        std::cout << "Error: bit stock file does not open" << std::endl;
        return 3;
    }
    getline(inputBitStock, bitPriceLine);
    if (bitPriceLine != "date,exchange_rate")
    {
        std::cout << "Error: wrong database file format" << std::endl;
        return 2;
    }
    while(getline(inputBitStock, bitPriceLine)){
        try
        {
            key = bitcoinExchange.readDateKey(bitPriceLine);
            valueToAdd = bitcoinExchange.readValuePrice(bitPriceLine);
            std::map<int, double>::iterator it = priceMap.find(key);
            if (it != priceMap.end()) {
                std::cout << "Warning: Price entry at date "<< key << " already mapped, not overwritten with redundant value " << it->second << std::endl;
            } else {
                priceMap[key] += valueToAdd;
            }
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what() << " at " << bitPriceLine << "\n";
        }
    }
  
    inputBitStock.close();
    getline(inputBitMine, bitMineLine);

    if (bitMineLine != "date | value")
    {
        std::cout << "Error: wrong data entry file format" << std::endl;
        return 3;
    }
	while(getline(inputBitMine, bitMineLine)){
        try
        {
            key = bitcoinExchange.readDateKey(bitMineLine);
            coinAmmount = bitcoinExchange.readValueCoin(bitMineLine);
            bitcoinExchange.priceCoinAmmount(priceMap, key, coinAmmount);
        }
       	catch(const std::exception &e)
        {
            std::cerr << e.what() << " at " << bitMineLine << "\n";
        }
	}
    inputBitMine.close();
}
