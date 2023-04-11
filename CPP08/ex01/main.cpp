#include "span.hpp"

int main()
{
    Span span(10000);

    try
    {
        for(int i = 0; i < 10000; i++)
            span.addNumber();
    }
    catch(const std::exception & e)
	{
		std::cerr << e.what();
	}
    span.shortestSpan();
    span.longestSpan();
}
