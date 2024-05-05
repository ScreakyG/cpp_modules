#include "Serializer.hpp"

Serializer::Serializer(void) {}
Serializer::~Serializer() {}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	(void)src;
}

Serializer& Serializer::operator=(const Serializer &rhs)
{
	std::cout << "Serializer assignement operator called" << std::endl;
	if (this != &rhs)
		std::cout << "Assigned from serializer copy assignement" << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
