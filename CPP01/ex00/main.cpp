/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:12:39 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/23 23:12:41 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
	Zombie foo("Foo");
	randomChump("Random");
	Zombie	*Malloced = newZombie("Malloced");
	std::cout << "Debug" << std::endl;
	delete Malloced;
}