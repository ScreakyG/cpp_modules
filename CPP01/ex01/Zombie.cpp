/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:21 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/23 23:13:23 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name_init) : _name(name_init)
{

}

Zombie::Zombie(void)
{
	//std::cout << "Zombie spawned" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " : Destructor called" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}
