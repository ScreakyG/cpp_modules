/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 06:35:02 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/23 03:26:46 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->_name = "DefaultScav";
	this->_vie = 100;
	this->_energy = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Name ScavTrap constructor called" << std::endl;
	_vie = 100;
	_energy = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap deconstructor called" << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout << "ScavTrap copy assignement operator called " << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void ScavTrap::guardGate(void)
{
	if (this->_vie > 0)
		std::cout << this->_name << " as entered in gate keeper mode" << std::endl;
	else
		std::cout << this->_name << " is dead and cannot use gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_vie > 0 && this->_energy > 0)
	{
		this->_energy -= 1;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else if (this->_vie <= 0)
		std::cout << "ScavTrap " << this->_name << " is dead and cannot attack." << std::endl;
	else if (this->_energy <= 0)
		std::cout << "ScavTrap " << this->_name << " have not enough energy to attack." << std::endl;
}

void ScavTrap::printStatus(void) const
{
	std::cout << "Name = " << this->_name << std::endl;
	std::cout << "Hit points = " << this->_vie << std::endl;
	std::cout << "Energy = " << this->_energy << std::endl;
	std::cout << "Attack = " << this->_attackDamage << std::endl;
}

void ScavTrap::setDefaultAD(void)
{
	this->_attackDamage = 20;
}

void ScavTrap::setDefaultEP(void)
{
	this->_energy = 50;
}

void ScavTrap::setDefaultHP(void)
{
	this->_vie = 100;
}
