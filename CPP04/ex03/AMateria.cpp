/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:01:03 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/24 19:19:03 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

AMateria::AMateria(void) : _type("Default")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria deconstructor called" << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

AMateria& AMateria::operator=(const AMateria& src)
{
	std::cout << "AMateria copy assignement called" << std::endl;
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
	std::cout << "What is " << this->_type << ", i can't use this on " << target.getName() << std::endl;
}
