#include "Zombie.hpp"

Zombie::Zombie(std::string name_init) : _name(name_init)
{

}

Zombie::Zombie(void) : _name("Default")
{

}

Zombie::~Zombie(void)
{
	std::cout << _name << " : Destructor called" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}