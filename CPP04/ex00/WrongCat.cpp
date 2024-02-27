/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:18:30 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:13:25 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << YELLOW "WrongCat constructor called" RESET << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal()
{
	std::cout << YELLOW "WrongCat copy constructor called" RESET << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED "WrongCat deconstructor called" RESET << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << YELLOW "WrongCat assignement operator called" RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void WrongCat::makeSound(void) const
{
	std::cout << this->_type << " : MIAOUUUUUU" << std::endl;
}
