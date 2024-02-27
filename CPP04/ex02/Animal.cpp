/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:44:58 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:50:16 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

#include "Animal.hpp"

AAnimal::AAnimal(void) : _type("Animal")
{
	std::cout << YELLOW "Animal constructor called" RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& src)
{
	std::cout << YELLOW "Animal copy constructor called" RESET << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << RED "Animal deconstructor called" RESET << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

AAnimal& AAnimal::operator=(const AAnimal& src)
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

void AAnimal::makeSound(void) const
{
	std::cout << this->_type << " : no sound" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
