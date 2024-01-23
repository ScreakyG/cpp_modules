/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:36:12 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/23 00:47:20 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ClapTrap::ClapTrap(void) : _name("DefaultClap"), _vie(10), _energy(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _vie(10), _energy(10), _attackDamage(0)
{
	std::cout << "ClapTrap Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap deconstructor called" << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

ClapTrap& ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "ClapTrap Copy assignement operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_vie = src._vie;
		this->_energy = src._energy;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void ClapTrap::attack(const std::string &name)
{
	if (this->_vie > 0 && this->_energy > 0)
	{
		this->_energy -= 1;
		std::cout << "ClapTrap " << this->_name << " attacks " << name << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else if (this->_vie <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack." << std::endl;
	else if (this->_energy <= 0)
		std::cout << "ClapTrap " << this->_name << " have not enough energy to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_vie > 0)
	{
		std::cout << this->_name << " takes " << amount << " damages." << std::endl;
		this->_vie -= amount;
	}
	else
		std::cout << this->_name << " is already dead." << std::endl;
	if (this->_vie <= 0)
		std::cout << this->_name << " is dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_vie > 0 && this->_energy > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repaired " << amount << std::endl;
		this->_vie += amount;
		this->_energy -= 1;
	}
	else if (this->_vie <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead and cannot repair." << std::endl;
	else if (this->_energy <= 0)
		std::cout << "ClapTrap " << this->_name << " have not enough energy to repair." << std::endl;
}

void ClapTrap::getHealth(void) const
{
	std::cout << this->_name << " have " << this->_vie << " health points." << std::endl;
}
