/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:20:50 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/24 20:16:37 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		void attack(void) const;
	private:
		std::string _humanName; 
		Weapon&		_arme;
};

#endif