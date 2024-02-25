/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:13:39 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/25 23:43:18 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Cure::Cure(void) : AMateria("cure")
{
	std::cout << YELLOW "Cure default constructor called" RESET << std::endl;
}

Cure::Cure(const Cure& src) : AMateria()
{
	std::cout << YELLOW "Cure copy constructor called" RESET << std::endl;
	*this = src;
}

Cure::~Cure(void)
{
	std::cout << RED "Cure deconstructor called" RESET << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

Cure& Cure::operator=(const Cure& src)
{
	std::cout << YELLOW "Cure copy assignement called" RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

AMateria* Cure::clone(void) const
{
	AMateria* clone = new Cure(*this);
	if (!clone)
		return (NULL);
	return (clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
