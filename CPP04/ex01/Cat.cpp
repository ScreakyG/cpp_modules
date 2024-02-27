/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:50:25 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:30:18 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), _brain(new Brain())
{
	if (!_brain)
		std::cout << "Failed to allocate memory for Brain" << std::endl;
	std::cout << YELLOW "Cat constructor called" RESET << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(), _brain(NULL)
{
	std::cout << YELLOW "Cat copy constructor called" RESET << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << RED "Cat deconstructor called" RESET << std::endl;
	delete _brain;
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
		if (this->_brain)
			delete _brain;
		_brain = new Brain(*src._brain);
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
