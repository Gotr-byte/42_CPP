#pragma once
#include <iostream>

class Data
{
    public:
        Data();
        ~Data();
        Data(Data& other);
        Data& operator = (Data& other);
        int getX();
        double getY();
        void printValues();
        void setXy(int x, double y);
    private:
        int _x;
        double _y;
};
