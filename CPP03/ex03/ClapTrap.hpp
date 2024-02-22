/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:35:32 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/22 17:09:33 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "iostream"

class ClapTrap
{
	public:
		ClapTrap(void); // Canonical.
		ClapTrap(ClapTrap const & src); // Canonical , recopie.
		ClapTrap(std::string name);
		~ClapTrap(void); // Canonical.
		ClapTrap& operator=(ClapTrap const &src); // Canonical assignement operator.

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void getHealth(void) const;

	protected:
		std::string _name;
		int _hitPoints;
		int _energy;
		int _attackDamage;
};

#endif
