/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:23:31 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/24 19:48:46 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _humanName(name), _arme(weapon)
{
	
}

void HumanA::attack(void) const
{
	std::cout << _humanName << " attacks with their " << _arme.getType() << std::endl;
}