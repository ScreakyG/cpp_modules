/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:17:25 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/25 23:41:46 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Ice::Ice(void) : AMateria("ice")
{
	std::cout << YELLOW "Ice default constructor called" RESET << std::endl;
}

Ice::Ice(const Ice& src) : AMateria()
{
	std::cout << YELLOW "Ice copy constructor called" RESET << std::endl;
	*this = src;
}

Ice::~Ice(void)
{
	std::cout << RED "Ice deconstructor called" RESET << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

Ice& Ice::operator=(const Ice& src)
{
	std::cout << YELLOW "Ice copy assignement called" RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

AMateria* Ice::clone(void) const
{
	AMateria* clone = new Ice(*this);
	if (!clone)
		return (NULL);
	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
