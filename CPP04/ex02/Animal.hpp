/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:33 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/23 21:00:30 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:

		AAnimal(void);
		AAnimal(const AAnimal& src);
		virtual ~AAnimal(void);
		AAnimal& operator=(const AAnimal& src);

		virtual void makeSound(void) const = 0;

		std::string getType(void) const;

	protected:
		std::string _type;
};

#endif
