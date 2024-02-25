/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:10:27 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/25 19:36:32 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource deconstructor called" << std::endl;
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
	std::cout << "MateriaSource copy assignement constructor called" << std::endl;
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
		std::cout << "Could not learn materia because in does not exist" << std::endl;
		return ;
	}

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << "Learned materia " << materia->getType() << std::endl;
			return ;
		}
	}
	std::cout << "I cant learn more than 4 materias" << std::endl;
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
				std::cout << "Creating " << type << " materia" << std::endl;
				return (this->_inventory[i]->clone());
			}
		}
	}
	std::cout << "MateriaSource have not learn this type" << std::endl;
	return (0);
}

void MateriaSource::showRecipes(void) const
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
			std::cout << "Empty slot" << std::endl;
		else
			std::cout << this->_inventory[i]->getType() << std::endl;
	}
	return ;
}
