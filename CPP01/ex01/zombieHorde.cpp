/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:37 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/23 23:13:39 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int	i;

	i = 0;
	if (N <= 0)
	{
		std::cout << "Horde must at least have 1 zombie" << std::endl;
		return (NULL);
	}
	Zombie	*horde = new Zombie[N];
	if (!horde)
	{
		std::cout << "Horde malloc failed" << std::endl;
		return (NULL);
	}
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}