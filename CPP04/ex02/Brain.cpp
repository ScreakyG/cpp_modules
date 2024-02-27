/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:04:52 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:50:52 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Brain::Brain(void)
{
	std::cout << YELLOW "Brain constructor called" RESET << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << YELLOW "Brain copy constructor called" RESET << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << RED "Brain deconstructor called" YELLOW << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

Brain& Brain::operator=(const Brain& src)
{
	int	i;

	std::cout << YELLOW "Brain assignement operator called" RESET << std::endl;
	if (this != &src)
	{
		for (i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void Brain::setIdeas(int index, std::string str)
{
	if (index < 0 )
		return ;
	else
		this->_ideas[index % 100] = str;
}

void Brain::printIdeas(void) const
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_ideas[i].empty() == 0)
			std::cout << this->_ideas[i] << std::endl;
	}
}
