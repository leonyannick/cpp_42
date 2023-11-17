#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct s_Data {
	std::string	content;
} Data;

class Serializer
{
public:
	// public methods
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

private:
	Serializer(void);
};

#endif