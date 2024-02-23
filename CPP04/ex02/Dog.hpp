/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:13:37 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/23 21:00:54 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(const Dog& src);
		~Dog(void);
		Dog& operator=(const Dog& src);

		void makeSound(void) const;

		Brain* getBrain(void) const;

	private:
		Brain*	_brain;
};

#endif
