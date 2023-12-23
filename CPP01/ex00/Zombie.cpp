/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:00 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/23 23:13:02 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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