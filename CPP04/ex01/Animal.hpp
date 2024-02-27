/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:33 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:26:56 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Color.h"

class Animal
{
	public:

		Animal(void);
		Animal(const Animal& src);
		virtual ~Animal(void);
		Animal& operator=(const Animal& src);

		virtual void makeSound(void) const;

		std::string getType(void) const;

	protected:
		std::string _type;
};

#endif
