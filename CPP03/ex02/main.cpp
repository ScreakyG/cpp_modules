/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:35:19 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/22 17:02:54 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap Frag("Frag");
	ScavTrap Scav("Scav");
	ClapTrap Clap("Clap");

	std::cout << "<---------------------------------------->" << std::endl;

	Frag.printStatus();

	std::cout << "<---------------------------------------->" << std::endl;

	Frag.highFiveGuys();
	Scav.guardGate();

	std::cout << "<---------------------------------------->" << std::endl;

	Frag.takeDamage(50);
	Frag.getHealth();
	Frag.beRepaired(30);
	Frag.getHealth();

	std::cout << "<---------------------------------------->" << std::endl;

	Clap.attack("Frag");
	Frag.attack("Clap");
	Scav.attack("Frag");

	std::cout << "<---------------------------------------->" << std::endl;
}
