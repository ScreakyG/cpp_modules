/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:35:19 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/22 17:39:50 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap Diamond("Diamond");
	ScavTrap	Scav("Scav");
	FragTrap	Frag("Frag");
	ClapTrap	Clap("Clap");

	std::cout << "<---------------------------------->" << std::endl;

	Diamond.whoAmI();
	Diamond.guardGate();
	Diamond.highFiveGuys();

	std::cout << "<---------------------------------->" << std::endl;

	Diamond.printStatus();

	std::cout << "<---------------------------------->" << std::endl;

	Diamond.attack("Scav");
	Scav.attack("Diamond");
	Frag.attack("Diamond");
	Clap.attack("Diamond");

	std::cout << "<---------------------------------->" << std::endl;

	Diamond.takeDamage(10);
	Diamond.getHealth();
	Diamond.beRepaired(5);

	std::cout << "<---------------------------------->" << std::endl;

	Diamond.printStatus();

	std::cout << "<---------------------------------->" << std::endl;

	Diamond = DiamondTrap("Fresh");

	std::cout << "<---------------------------------->" << std::endl;

	Diamond.printStatus();

	std::cout << "<---------------------------------->" << std::endl;
}
