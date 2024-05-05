#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	uintptr_t serialized;
	Data test1 = {10};

	std::cout << "test1 value : " << test1.value << std::endl;
	std::cout << "Adress of object test1 : " << &test1 << std::endl;

	std::cout << std::endl;

	serialized = Serializer::serialize(&test1);
	std::cout << "uintptr_t from serialized test1 adress : " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Adress pointed to after deserialize : " << deserialized << std::endl;

	if (deserialized == &test1)
	{
		std::cout << GREEN << "New pointer points to the adress of test1" << RESET << std::endl;
		std::cout << "Value of deserialized uintptr_t object : " << deserialized->value << std::endl;
	}
	else
		std::cout << RED << "New pointer does not points to the adress of test1" << RESET << std::endl;
}
