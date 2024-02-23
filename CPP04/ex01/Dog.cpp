/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:14:53 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/23 19:19:54 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

#include "Dog.hpp"

Dog::Dog(void) : Animal(), _brain(new Brain())
{
	if (!_brain)
		std::cout << "Failed to allocate memory for Brain" << std::endl;
	std::cout << "Dog constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& src) : Animal(), _brain(NULL)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog deconstructor called" << std::endl;
	delete _brain;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog assignement operator called" << std::endl;
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

void Dog::makeSound(void) const
{
	std::cout << this->_type << " : WOUAF WOUAF" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (this->_brain);
}
