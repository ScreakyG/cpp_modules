/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:12:39 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/19 14:59:07 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main(void)
{
	Zombie foo("Foo");
	foo.announce();

	std::cout << "<--------------------------------------------->" << std::endl;

	randomChump("Default");

	std::cout << "<--------------------------------------------->" << std::endl;

	Zombie	*malloced = newZombie("Malloced");
	malloced->announce();

	std::cout << "<--------------------------------------------->" << std::endl;
	randomChump("Default2");

	delete malloced;
}
