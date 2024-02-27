/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:14:27 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:12:24 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << YELLOW "WrongAnimal constructor called" RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << YELLOW "WrongAnimal copy constructor called" RESET << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED "WrongAnimal deconstructor called" RESET << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << YELLOW "WrongAnimal assignement operator called" RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void WrongAnimal::makeSound(void) const
{
	std::cout << this->_type << " : no sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}
