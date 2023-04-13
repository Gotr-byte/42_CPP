#include <iostream>
#include <fstream>

//input a filename and two strings
int main ()
{
    std::string         bitMine = "bitMine.csv";
	std::string         bitPrice = "bitStock.csv";
	std::string			bitAmmount;
	std::string			bitPrices;

    std::ifstream       inputBitMine(bitMine);
    if (!inputBitMine){
        std::cout << "Input file does not open" << std::endl;
        return 2;
    }
	std::ifstream       inputBitPrice(bitPrice);
	if (!inputBitPrice){
        std::cout << "Input file does not open" << std::endl;
        return 2;
    }
	 while(getline(inputBitMine, bitAmmount)){}
    inputBitMine.close();
	 while(getline(inputBitPrice, bitPrices)){}
    inputBitPrice.close();
	std::cout << "+++Input from BitMine.scv+++\n";
	std::cout << bitAmmount << "\n";
	std::cout << "+++Input from BitMine.scv+++\n";
	std::cout << bitPrices << "\n";

}
