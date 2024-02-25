/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:49:53 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/26 00:01:41 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Character::Character(void) : _name("Default")
{
	std::cout << YELLOW "Character default constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << YELLOW "Character name constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& src)
{
	std::cout << YELLOW "Character copy constructor called" RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

Character::~Character(void)
{
	std::cout << RED "Character deconstructor called" YELLOW << std::endl;
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
	std::cout << YELLOW "Character copy assignement called" RESET << std::endl;
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
		std::cout << this->_name << RED " : Could not equip materia because in does not exist" RESET << std::endl;
		return ;
	}
	for (idx = 0; idx < 4; idx++)
	{
		if (_inventory[idx] == m)
		{
			std::cout << this->_name << RED " : You already have this materia at slot " RESET << idx << std::endl;
			return ;
		}
		else if (_inventory[idx] == NULL)
		{
			_inventory[idx] = m;
			std::cout << this->_name << GREEN " : AMateria " RESET << m->getType() << GREEN " added to inventory at slot " RESET << idx << std::endl;
			return ;
		}
	}
	std::cout << RED "Inventory is full" RESET << std::endl;
}

void Character::unequip(int idx)
{

	if (idx < 0 || idx > 3)
	{
		std::cout << this->_name << RED " : No item in this slot" RESET << std::endl;
		return ;
	}

	if (this->_inventory[idx])
	{
		this->_inventory[idx] = NULL;
		std::cout << this->_name << GREEN " : Item removed at slot " RESET << idx << std::endl;
	}
	else
		std::cout << this->_name << RED " : This slot is empty" RESET << std::endl;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << this->_name << RED " : Invalid slot" RESET << std::endl;
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << this->_name << RED " : Can't use a empty slot" RESET << std::endl;
}

void Character::showInventory(void) const
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
