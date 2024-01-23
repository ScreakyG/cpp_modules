/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:18:41 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/23 03:49:43 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
	FragTrap::setDefaultHP();
	ScavTrap::setDefaultEP();
	FragTrap::setDefaultAD();

	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->_name = "DefaultDiamond";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_vie = FragTrap::_vie;
	this->_energy = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
	*this = src;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(), ScavTrap(), _name(name)
{
	FragTrap::setDefaultHP();
	ScavTrap::setDefaultEP();
	FragTrap::setDefaultAD();

	std::cout << "Name DiamondTrap constructor called" << std::endl;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_vie = FragTrap::_vie;
	this->_energy = ScavTrap::_energy;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap deconstructor called" << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap copy assignement operator called " << std::endl;
	if (this != &src)
	{
		ClapTrap::_name = src.ClapTrap::_name;
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

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is : " << this->_name << " and my ClapTrap name is : " << ClapTrap::_name << std::endl;
}

void DiamondTrap::printStatus(void) const
{
	std::cout << "ClapTrap Name = " << ClapTrap::_name << std::endl;
	std::cout << "Name = " << this->_name << std::endl;
	std::cout << "Hit points = " << this->_vie << std::endl;
	std::cout << "Energy = " << this->_energy << std::endl;
	std::cout << "Attack = " << this->_attackDamage << std::endl;
}
