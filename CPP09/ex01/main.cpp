#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
		RPN::Calculate(argv[1]);
	else
		std::cerr << "Wrong usage" << std::endl;
}
