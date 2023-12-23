/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:16 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/23 23:13:18 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
	int	i = 0;
	int	nb = 5;
	Zombie	*horde = zombieHorde(nb, "Hordeux");
	while (i < nb)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
}