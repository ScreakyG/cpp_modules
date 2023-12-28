/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:28:28 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/28 20:52:54 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl test;
	test.complain("debug");
	test.complain("info");
	test.complain("warning");
	test.complain("error");
	test.complain("other");
	return (0);
}