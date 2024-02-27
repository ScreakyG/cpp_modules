/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal
.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:12:27 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/23 15:12:57 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include "Color.h"

class WrongAnimal

{
	public:

		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& src);
		virtual ~WrongAnimal(void);
		WrongAnimal& operator=(const WrongAnimal& src);

		void makeSound(void) const;

		std::string getType(void) const;

	protected:
		std::string _type;
};

#endif
