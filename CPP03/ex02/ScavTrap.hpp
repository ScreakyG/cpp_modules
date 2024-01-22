/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 06:35:29 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/20 08:01:06 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void); // Canonical.
		ScavTrap(ScavTrap const &src); // Canonical.
		ScavTrap(std::string name);
		~ScavTrap(void); // Canonical.
		ScavTrap& operator=(const ScavTrap& src); // Canonical.

		void guardGate(void);
		void attack(const std::string &target);
		void printStatus(void) const;
};

#endif
