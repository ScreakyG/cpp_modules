/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:29:15 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/28 20:53:48 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	
}

Harl::~Harl(void)
{
	
}

void Harl::complain(std::string level)
{
	std::string name[] = {"debug", "info", "warning", "error"};
	void (Harl::*fptr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::size_t i = 0;

	while (i < name->length())
	{
		if (level == name[i])
		{
			(this->*(fptr[i]))();
			return ;
		}
		i++;
	}
	std::cout << "I have no idea what you want" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}