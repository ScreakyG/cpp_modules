/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:12:02 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/23 03:24:43 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->_name = "DefaultFrag";
	this->_vie = 100;
	this->_energy = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Name FragTrap constructor called" << std::endl;
	_vie = 100;
	_energy = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap()
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap deconstructor called" << std::endl;
}

/******************************************************************************/
/*						OPERATORS							  				  */
/******************************************************************************/

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout << "FragTrap copy assignement operator called " << std::endl;
	if (this != &src)
	{
		ClapTrap::operator=(src);
	}
	return (*this);
}

/******************************************************************************/
/*						FUNCTIONS							  				  */
/******************************************************************************/

void FragTrap::highFiveGuys(void)
{
	if (this->_vie > 0)
		std::cout << this->_name << " asked for a high fives." << std::endl;
}

void FragTrap::setDefaultAD(void)
{
	this->_attackDamage = 30;
}

void FragTrap::setDefaultEP(void)
{
	this->_energy = 100;
}

void FragTrap::setDefaultHP(void)
{
	this->_vie = 100;
}

