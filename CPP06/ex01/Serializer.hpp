#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#define RESET	"\e[0m"
#define RED		"\e[31m"
#define GREEN	"\e[32m"
#define YELLOW	"\e[33m"
#define BLUE	"\e[34m"
#define PURPLE	"\e[35m"
#define CYAN	"\e[36m"

class Data;

class Serializer
{
	public:
		~Serializer();
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
    private:
        Serializer();
        Serializer(const Serializer &src);
        Serializer &operator=(const Serializer &rhs);
};

#endif
