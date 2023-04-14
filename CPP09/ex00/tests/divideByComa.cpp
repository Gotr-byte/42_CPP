#include <iostream>
#include <string>
#include <cstdlib>



//needs input check
int readDateKey(std::string inputLine)
{
    // std::string inputLine = "2022-11-12, 23.3";

    std::string year = inputLine.substr(0,4);
    std::string month = inputLine.substr(5,2);
    std::string day = inputLine.substr(8,2);
    std::string date = year + month + day;
    int dateKey = atoi(date.c_str());
    std::cout << "the date in integer equals: " << dateKey << "\n";
    return 0;
}

