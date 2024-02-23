/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:50:25 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/23 19:17:26 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal(), _brain(new Brain())
{
	if (!_brain)
		std::cout << "Failed to allocate memory for Brain" << std::endl;
	std::cout << "Cat constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& src) : Animal(), _brain(NULL)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat deconstructor called" << std::endl;
	delete _brain;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat assignement operator called" << std::endl;
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
