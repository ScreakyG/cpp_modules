/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:28:28 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/29 01:20:35 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl test;
	if (argc == 2)
		test.complain(argv[1]);
	else
		std::cout << "You must specify a level." << std::endl;
	return (0);
}