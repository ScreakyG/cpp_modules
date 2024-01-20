/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:35:19 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/20 08:20:27 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap screaky("Screaky");
	ClapTrap shibukkai("Shibukkai");

	shibukkai = screaky;
	shibukkai.getHealth();
}
