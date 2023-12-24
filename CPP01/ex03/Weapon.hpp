/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:54:59 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/24 20:16:12 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon(void);
		Weapon(std::string name);
		const std::string& getType(void) const;
		void setType(std::string name);
	private:
		std::string _type;
};

#endif