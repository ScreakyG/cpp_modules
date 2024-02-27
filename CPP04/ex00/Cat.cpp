/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:50:25 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:10:48 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << YELLOW "Cat constructor called" RESET << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& src) : Animal()
{
	std::cout << YELLOW "Cat copy constructor called" RESET << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << RED "Cat deconstructor called" RESET << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

Cat& Cat::operator=(const Cat& src)
{
	std::cout << YELLOW "Cat assignement operator called" RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void Cat::makeSound(void) const
{
	std::cout << this->_type << " : MIAOUUUUUU" << std::endl;
}
