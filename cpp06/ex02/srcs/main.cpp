#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>


Base*	generate() {
	std::srand(std::time(NULL));
	//generate a random number 1, 2 or 3
	int randNum = (rand() % 3) + 1;
	switch (randNum)
	{
	case (1):
		return(new A());
	case (2):
		return(new B());
	case (3):
		return(new C());
	}
	return (NULL);
}

/**
 * with pointers dynamic cast does not throw an exception,
 * so we have to check the return value
*/
void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type C" << std::endl;
	else
		std::cout << "only god knows what pointer you gave me" << std::endl;
}

/**
 * for references dynamic cast throws a bad_cast exception when the cast fails,
 * we simply ignore the exception
*/
void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "type A" << std::endl;
	}
	catch (std::exception& e) {
		// std::cout << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "type B" << std::endl;
	}
	catch (std::exception& e) {
		// std::cout << e.what() << std::endl;
	}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "type C" << std::endl;
	}
	catch (std::exception& e) {
		// std::cout << e.what() << std::endl;
	}
}

int	main(void) {
	Base* ret = generate();
	identify(ret);
	identify(*ret);
	delete ret;
	return (EXIT_SUCCESS);
}
