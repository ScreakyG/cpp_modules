/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:35:19 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/22 17:09:25 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Bob("Bob");
	ClapTrap Joe("Joe");
	ClapTrap Default;

	std::cout << "<------------------------------------->" << std::endl;

	Bob.attack("Joe");
	Bob.getEnergyPoints();
	Joe.takeDamage(2);
	Joe.beRepaired(1);
	Joe.getHealth();
	Joe.getEnergyPoints();

	std::cout << "<------------------------------------->" << std::endl;

	Bob = Joe;
	Bob.getHealth();

	std::cout << "<------------------------------------->" << std::endl;
}
