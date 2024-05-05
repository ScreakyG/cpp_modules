#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
//	uintptr_t adress;
	Data test1 = {10};

	std::cout << "test1 value : " << test1.value << std::endl;
	std::cout << "Adress of object test1 : " << &test1 << std::endl;

	std::cout << "uintptr_t value of test1 adress : " << Serializer::serialize(&test1) << std::endl;
	std::cout << "Adress of object test1 after deserializer : " << Serializer::deserialize(Serializer::serialize(&test1)) << std::endl;

	// std::cout << "Original pointer adress = " << test << std::endl;
	// adress = Serializer::serialize(test);

	// std::cout << adress << std::endl;
	// std::cout << Serializer::deserialize(adress) << std::endl;
	// if (test)
	// 	delete test;
}
