#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange & operator = (const BitcoinExchange &other);
        ~BitcoinExchange();

        void        printMap(const std::map<int, double>& myMap);
        int         readDateKey(std::string inputLine);
        double      readValuePrice(std::string inputLine);
        double      readValueCoin(std::string inputLine);
        int         priceCoinAmmount(std::map<int, double> &myMap, int target, double coinAmmout);
        static bool dateValid(int year, int month, int day);
        class				        InvalidDateException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Invalid Date at entry");
				}
		};
        class				        BitValueTooLow : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Error: value too low at entry");
				}
		};
        class				        BitValueTooHigh : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Error: value too high at entry");
				}
		};
        class				        BitValueTooManyDigits : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Error: value contains too many digits");
				}
		};
        class				        InvalidFormat : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return("Error: wrong data format");
				}
		};
    private:
};
