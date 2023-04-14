// c++ getPriceFromFile.cpp -o getPriceFromFile
#include <iostream>
#include <cstdlib>
#include <string>

double readValuePrice(std::string inputLine) {
    //  std::string inputLine = "2022-11-12,123567623.37";

    // Find the position of the first newline character after position 11
    size_t startPos = 11;
    size_t endPos = inputLine.find('\n', startPos);

    // Extract the substring from startPos up to (but not including) the newline character
    std::string priceToCast = inputLine.substr(startPos, endPos - startPos);
    
    std::cout << "Substring: " << priceToCast << std::endl;
    double priceToReturn = atof(priceToCast.c_str());
    return priceToReturn;
}

int main()
{
    std::cout << readValuePrice("1111-11-11,1234.12") << "\n";
}