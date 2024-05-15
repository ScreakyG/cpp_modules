#include "Array.hpp"

int main(void)
{
	Array<int> a;
	Array<int> b(10);

	std::cout << "Array a size = " << a.size() << std::endl;
	std::cout << "Array b size = " << b.size() << std::endl;

	b = a;

	std::cout << "Array b size = " << a.size() << std::endl;
}
