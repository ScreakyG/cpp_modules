/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:14:53 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:11:34 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << YELLOW "Dog constructor called" RESET << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& src) : Animal()
{
	std::cout << YELLOW "Dog copy constructor called" RESET << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << RED "Dog deconstructor called" RESET << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

Dog& Dog::operator=(const Dog& src)
{
	std::cout << YELLOW "Dog assignement operator called" RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void Dog::makeSound(void) const
{
	std::cout << this->_type << " : WOUAF WOUAF" << std::endl;
}
