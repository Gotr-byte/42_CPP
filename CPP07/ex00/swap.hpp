#pragma once
template<typename T>
void swap(T &a, T &b)
{
    T tmp;
    tmp = b;
    b = a;
    a = tmp;
}
