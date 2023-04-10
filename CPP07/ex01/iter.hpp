#pragma once

template<typename T>
void iter(T *arrPtr, int len, void (*fun)(T &))
{
    int i = 0;
    while (i < len)
    {
        fun(arrPtr[i]);
        i++;
        std::cout << i;
    }
}

