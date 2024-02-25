/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:49:53 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/25 18:17:02 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Character::Character(void) : _name("Default")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& src)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

Character::~Character(void)
{
	std::cout << "Character deconstructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

Character& Character::operator=(const Character& src)
{
	std::cout << "Character copy assignement called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
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

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	int	idx;

	if (!m)
	{
		std::cout << this->_name << " : Could not equip materia because in does not exist" << std::endl;
		return ;
	}
	for (idx = 0; idx < 4; idx++)
	{
		if (_inventory[idx] == m)
		{
			std::cout << this->_name <<" : You already have this materia at slot " << idx << std::endl;
			return ;
		}
		else if (_inventory[idx] == NULL)
		{
			_inventory[idx] = m;
			std::cout << this->_name << " : AMateria " << m->getType() << " added to inventory at slot " << idx << std::endl;
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{

	if (idx < 0 || idx > 3)
	{
		std::cout << this->_name << " : No item in this slot" << std::endl;
		return ;
	}

	if (this->_inventory[idx])
	{
		this->_inventory[idx] = NULL;
		std::cout << this->_name << " : Item removed at slot " << idx << std::endl;
	}
	else
		std::cout << this->_name << " : This slot is empty" << std::endl;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << this->_name << " : Invalid slot" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << this->_name << " : Can't use a empty slot" << std::endl;
}

void Character::showInventory(void) const
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
