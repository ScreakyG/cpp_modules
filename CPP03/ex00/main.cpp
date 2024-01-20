/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:35:19 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/18 22:24:46 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Bob("Bob");
	ClapTrap Joe("Joe");

	Bob.attack("Joe");
	Joe.takeDamage(2);
	Joe.beRepaired(1);
	Joe.getHealth();
}
