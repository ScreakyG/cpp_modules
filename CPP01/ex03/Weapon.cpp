/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:57:48 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/24 19:38:23 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type("Default")
{
	
}

Weapon::Weapon(std::string name) : _type(name)
{
	
}

const std::string& Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string name)
{
	this->_type = name;
}