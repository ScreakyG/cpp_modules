/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:35:19 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/22 17:07:20 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Bob("Bob");
	ClapTrap Billy("Billy");

	std::cout << "<------------------------------------->" << std::endl;

	Bob.printStatus();

	std::cout << "<------------------------------------->" << std::endl;

	Bob.guardGate();

	std::cout << "<------------------------------------->" << std::endl;

	Billy.attack("Bob");
	Bob.attack("Billy");

	std::cout << "<------------------------------------->" << std::endl;

	Billy.takeDamage(20);
	Bob.takeDamage(0);

	std::cout << "<------------------------------------->" << std::endl;

	Bob.takeDamage(10);
	Bob.getHealth();
	Bob.beRepaired(5);
	Bob.getHealth();

	std::cout << "<------------------------------------->" << std::endl;
}
