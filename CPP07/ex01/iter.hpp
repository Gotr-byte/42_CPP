#pragma once
#include <iostream>

template <typename T>
void iter(T *arrPtr, unsigned int len, void (* fun)(T const &)){
    while (len--)
        fun(arrPtr[len]);
}

template <typename T>
void iter(T *arrPtr, unsigned int len, void (* fun)(T &)){
    while (len--)
        fun(arrPtr[len]);
}
