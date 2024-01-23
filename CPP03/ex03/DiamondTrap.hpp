/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:11:39 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/23 03:40:02 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		DiamondTrap& operator=(const DiamondTrap &src);

		void whoAmI(void);
		void attack(const std::string &target);
		void printStatus(void) const;

	private:
		std::string _name;
};

#endif
