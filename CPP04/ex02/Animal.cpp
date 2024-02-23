/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:44:58 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/23 21:05:17 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

#include "Animal.hpp"

AAnimal::AAnimal(void) : _type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal deconstructor called" << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

AAnimal& AAnimal::operator=(const AAnimal& src)
{
	std::cout << "Animal assignement operator called" << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void AAnimal::makeSound(void) const
{
	std::cout << this->_type << " : no sound" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
