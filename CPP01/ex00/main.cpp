#include "Zombie.hpp"


int main(void)
{
	Zombie foo("Foo");
	randomChump("Random");
	Zombie	*Malloced = newZombie("Malloced");
	std::cout << "Debug" << std::endl;
	delete Malloced;
}