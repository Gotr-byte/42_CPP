#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <unordered_map>

class BitcoinExchange
{
    public:
        static void printMap(const std::map<int, double>& myMap);
        static int readDateKey(std::string inputLine);
        static double readValuePrice(std::string inputLine);
        static double readValueCoin(std::string inputLine);
        static int priceCoinAmmount(std::map<int, double> &myMap, int target, double coinAmmout);
        class				        InvalidDateException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Grade to high\n");
				}
		};
    private:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange & operator = (const BitcoinExchange &other);
        ~BitcoinExchange();
};