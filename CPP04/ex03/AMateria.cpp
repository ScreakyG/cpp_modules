/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:01:03 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/25 23:50:12 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

AMateria::AMateria(void) : _type("Default")
{
	std::cout << YELLOW "AMateria default constructor called" RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << YELLOW "AMateria type constructor called" RESET << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
	std::cout << YELLOW "AMateria copy constructor called" RESET << std::endl;
	*this = src;
}

AMateria::~AMateria(void)
{
	std::cout << RED "AMateria deconstructor called" RESET << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

AMateria& AMateria::operator=(const AMateria& src)
{
	std::cout << YELLOW "AMateria copy assignement called" RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

std::string const& AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << RED "What is " << this->_type << ", i can't use this on " RESET << target.getName() << std::endl;
}
