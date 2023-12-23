/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:13:27 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/23 23:13:29 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>



class Zombie
{
	public:
		Zombie(std::string name_init);
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName(std::string name);
	private:
		std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif