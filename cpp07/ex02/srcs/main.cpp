#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Array.hpp"
#include "iter.hpp"

template<typename T>
void	print(const T & t) {
	std::cout << t << std::endl;
}

class Test
{
  public:
    Test( void ) : _n( 13 ) { return; }
    int get( void ) const { return this->_n; }
	void set(int n) {_n = n;}
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Test const & rhs )
{
  o << rhs.get();
  return o;
}

int	main(void) {
	Array<int> intArr(5);
	Array<Test> testArr(7);
	intArr[2] = 3;

	std::cout << testArr << std::endl;
	try {
		testArr[6].set(5);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << testArr << std::endl;
	std::cout << std::endl;


	try {
		intArr[6] = 5;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << intArr << std::endl;
	std::cout << std::endl;

	Array<int> intArr2;
	try {
		std::cout << intArr2 << std::endl;
		intArr2[0] = 5;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	const Array<int> constTest(5);
	std::cout << constTest[4] << std::endl;
	//constTest[4] = 3; //doesnt work because const

	std::cout << std::endl;
	iter(&intArr[0], 5, print<int>);

	return (EXIT_SUCCESS);
}

// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

