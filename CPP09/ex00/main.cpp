#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>

//date validator



//input a filename and two strings
int main ()
{
    std::string         bitMineLine;
	std::string         bitPriceLine;

    std::ifstream       inputBitMine("bitMine.csv");
    if (!inputBitMine){
        std::cout << "Bit mine file does not open" << std::endl;
        return 2;
    }
	std::ifstream       inputBitStock("bitStock.csv");
    if (!inputBitMine){
        std::cout << "Bit stock file does not open" << std::endl;
        return 2;
    }
	while(getline(inputBitMine, bitMineLine)){
		std::cout << bitMineLine << std::endl;
	}
    inputBitMine.close();
	while(getline(inputBitStock, bitPriceLine)){
		std::cout << bitPriceLine << std::endl;
	}
    inputBitStock.close();
    // while(i < inputString.length())
    // {
    //     while (compareString[compareCount] == inputString[i + compareCount])
    //     {
    //         compareCount++;
    //         if (compareCount == compareString.length()) {
    //             outputFileStream << replacementString;
    //             i = i + compareCount;
    //         }
    //     }
    //     if (compareString[compareCount] != inputString[i])
    //     {
    //         outputFileStream << inputString[i];
    //         compareCount = 0;
    //     }
    //     if (i < inputString.length())
    //         i++;
    // }
    // outputFileStream.close();
}

// int main()
// {

// }