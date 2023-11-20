#include "Serializer.hpp"
#include <cstdlib>

int	main(void) {
	Data test;
	test.content = "hello there";
	std::cout << "adress of Data structure:" << &test << std::endl;

	uintptr_t ret = Serializer::serialize(&test);
	std::cout << "uinptr_t ret value from serialize:" << std::showbase << std::hex << ret << std::endl;
	Data *check = Serializer::deserialize(ret);
	std::cout << "Data pointer ret value from deserialize:" << check << std::endl;
	std::cout << "Dereferencing Data pointer:" << check->content << std::endl;
	return (EXIT_SUCCESS);
}
