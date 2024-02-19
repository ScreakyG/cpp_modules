/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:07:11 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/19 15:21:08 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _humanName(name), _arme(NULL)
{

}

void HumanB::attack(void) const
{
	if (_arme)
	{
		std::cout << _humanName << " attacks with their " << _arme->getType() << std::endl;
	}
	else
		std::cout << _humanName << " : have no weapon to attack so he use his hands" << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_arme = &weapon;
}
