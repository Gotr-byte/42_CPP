#include "swap.hpp"
#include "min.hpp"
#include "max.hpp"
#include <iostream>

int main()
{
    int a = 2;
    int b = 3;
    char c = 48;
    char d = 49;
    float e = 2;
    float f = 3;
    double g = 2;
    double h = 3;
    std::cout << "+++int test+++" << std::endl;
    std::cout << "a equals: " << a << std::endl;
    std::cout << "b equals: " << b << std::endl;
    swap(a, b);
    std::cout << "a equals: " << a << std::endl;
    std::cout << "b equals: " << b << std::endl;
    std::cout << "min(" << a <<", "<< b <<") = " << min(a,b) << std::endl;
    std::cout << "max(" << a <<", "<< b <<") = " << max(a,b) << std::endl;
    std::cout << std::endl;
    std::cout << "+++char test+++" << std::endl;
    std::cout << "c equals: " << c << std::endl;
    std::cout << "d equals: " << d << std::endl;
    swap(a, b);
    std::cout << "c equals: " << c << std::endl;
    std::cout << "d equals: " << d << std::endl;
    std::cout << "min(" << c <<", "<< d <<") = " << min(c,d) << std::endl;
    std::cout << "max(" << c <<", "<< d <<") = " << max(c,d) << std::endl;
    std::cout << std::endl;
    std::cout << "+++float test+++" << std::endl;
    std::cout << "e equals: " << e << std::endl;
    std::cout << "f equals: " << f << std::endl;
    swap(a, b);
    std::cout << "e equals: " << e << std::endl;
    std::cout << "f equals: " << f << std::endl;
    std::cout << "min(" << e <<", "<< f <<") = " << min(e,f) << std::endl;
    std::cout << "max(" << e <<", "<< f <<") = " << max(e,f) << std::endl;
    std::cout << std::endl;
    std::cout << "+++double test+++" << std::endl;
    std::cout << "g equals: " << g << std::endl;
    std::cout << "h equals: " << h << std::endl;
    swap(a, b);
    std::cout << "g equals: " << g << std::endl;
    std::cout << "h equals: " << h << std::endl;
    std::cout << "min(" << g <<", "<< h <<") = " << min(g,h) << std::endl;
    std::cout << "max(" << g <<", "<< h <<") = " << max(g,h) << std::endl;
    std::cout << std::endl;
}
