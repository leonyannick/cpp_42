#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Span.hpp"
#include <ctime>

template<typename T>
void	print(const T & t) {
	std::cout << t << std::endl;
}

int	main(void) {
	size_t	N = 20;
	Span span1(N);

	//generate random numbers
	std::srand(std::time(NULL));

	for (size_t i = 0; i < N; i++) {
		if (i == 14)
			span1.addNumber(5);
		else
			span1.addNumber(2);
	}
	
	std::cout  << "shortest span: " << span1.shortestSpan() << std::endl;
	std::cout << "longest span: " << span1.longestSpan() << std::endl;

	std::cout << "Span2:" << std::endl;
	Span span2(span1);
	std::cout << span2.shortestSpan() << std::endl;
	std::cout << span2.longestSpan() << std::endl;

	std::cout << "Span3:" << std::endl;
	Span span3(0);
	span3 = span1;
	std::cout << span3.shortestSpan() << std::endl;
	std::cout << span3.longestSpan() << std::endl;

	std::vector<int> range;
	range.push_back(3);
	range.push_back(-10);
	range.push_back(3);
	range.push_back(7);
	range.push_back(0);
	range.push_back(11);

	Span span4(4);
	try {
		span4.addNumbers(range.begin(), range.end());
	}
	catch (Span::SpanFullException &e) {
		std::cout << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }


