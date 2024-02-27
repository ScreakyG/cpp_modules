/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:44:58 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:27:28 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << YELLOW "Animal constructor called" RESET << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << YELLOW "Animal copy constructor called" RESET << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << RED "Animal deconstructor called" RESET << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

Animal& Animal::operator=(const Animal& src)
{
	std::cout << YELLOW "Animal assignement operator called" RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void Animal::makeSound(void) const
{
	std::cout << this->_type << " : no sound" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}
