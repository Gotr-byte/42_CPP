#include "span.hpp"

int main()
{
    Span span(10000);
    Span sp = Span(5);

    std::cout << "+++10000 number span test+++\n";
    try
    {
        for(int i = 0; i < 10000; i++)
            span.addRandNumber();
    }
    catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
    std::cout << span.shortestSpan() << "\n";
    std::cout << span.longestSpan() << "\n";
    std::cout << "+++end of 10000 number span test+++\n\n";
    std::cout << "+++set number span test+++\n";

    sp.addNumber(6); 
    sp.addNumber(3); 
    sp.addNumber(17); 
    sp.addNumber(9); 
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl; 
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "+++end of set number span test+++\n\n";

}
