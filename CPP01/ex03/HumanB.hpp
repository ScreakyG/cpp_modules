/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:03:09 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/24 20:21:12 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
		void attack(void) const;
	private:
		std::string _humanName;
		Weapon*		_arme;
};

#endif