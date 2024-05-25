#include <iostream>
#include "easyfind.hpp"

void	vectorTests(void)
{
	std::cout << CYAN "<-----VECTOR TESTS----->" RESET << std::endl;

	std::vector<int>					vector;
	std::vector<int>::const_iterator	it;

	try
	{
		vector.push_back(0);
		vector.push_back(42);
		vector.push_back(100);

		for (it = vector.begin(); it != vector.end(); it++)
			std::cout << "[" << *it << "]";
		std::cout << "\n";

		it = easyfind(vector, 42);
		std::cout << "Iterator pointing at value " << *it << std::endl;
		it = easyfind(vector, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << CYAN "<---------------------->" RESET << std::endl;
}

void	dequeTests(void)
{
	std::cout << CYAN "<-----ARRAY TESTS----->" RESET << std::endl;

	std::deque<int>					deque;
	std::deque<int>::const_iterator	it;

	try
	{
		deque.push_back(1);
		deque.push_front(2);

		for (it = deque.begin(); it != deque.end(); it++)
			std::cout << "[" << *it << "]";
		std::cout << "\n";

		it = easyfind(deque, 2);
		std::cout << "Iterator pointing at value " << *it << std::endl;
		it = easyfind(deque, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << CYAN "<---------------------->" RESET << std::endl;
}

int main(void)
{
	vectorTests();
	dequeTests();
}
