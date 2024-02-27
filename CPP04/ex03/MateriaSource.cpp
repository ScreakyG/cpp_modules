/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:10:27 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 15:49:29 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

MateriaSource::MateriaSource(void)
{
	std::cout << YELLOW "MateriaSource constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	std::cout << YELLOW "MateriaSource copy constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << RED "MateriaSource deconstructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
	std::cout << YELLOW "MateriaSource copy assignement constructor called" RESET << std::endl;
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			if (src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << RED "Could not learn materia because in does not exist" RESET << std::endl;
		return ;
	}

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == materia)
		{
			std::cout << RED "You have already learned this materia" RESET << std::endl;
			return ;
		}
		else if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << GREEN "Learned materia " RESET << materia->getType() << std::endl;
			return ;
		}
	}
	std::cout << RED "I cant learn more than 4 materias" RESET << std::endl;
	delete materia;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			if (type == this->_inventory[i]->getType())
			{
				std::cout << GREEN "Creating " RESET << type << GREEN " materia" RESET << std::endl;
				return (this->_inventory[i]->clone());
			}
		}
	}
	std::cout << RED "MateriaSource have not learn this type" RESET << std::endl;
	return (0);
}

void MateriaSource::showRecipes(void) const
{
	std::cout << "[";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
			std::cout << " empty_Slot ";
		else
			std::cout << this->_inventory[i]->getType() << " ";
	}
	std::cout << "]" << std::endl;
	return ;
}
