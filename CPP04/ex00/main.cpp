/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:53:48 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/23 15:35:41 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "<---------------------------------->" << std::endl;

	if (dog)
	{
		std::cout << dog->getType() << " " << std::endl;
		dog->makeSound();
	}

	std::cout << "<---------------------------------->" << std::endl;

	if (cat)
	{
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
	}

	std::cout << "<---------------------------------->" << std::endl;

	if (meta)
	{
		std::cout << meta->getType() << " " << std::endl;
		meta->makeSound();
	}
	std::cout << "<---------------------------------->" << std::endl;

	const WrongAnimal* base = new WrongAnimal();
	const WrongAnimal* wrongcat = new WrongCat();
	const WrongCat*		rightcat = new WrongCat();

	std::cout << "<---------------------------------->" << std::endl;

	if (base)
	{
		std::cout << base->getType() << std::endl;
		base->makeSound();
	}

	std::cout << "<---------------------------------->" << std::endl;

	if (wrongcat)
	{
		std::cout << wrongcat->getType() << std::endl;
		wrongcat->makeSound();
	}

	std::cout << "<---------------------------------->" << std::endl;

	if (rightcat)
	{
		std::cout << rightcat->getType() << std::endl;
		rightcat->makeSound();
	}

	std::cout << "<---------------------------------->" << std::endl;

	delete meta;
	delete dog;
	delete cat;
	delete wrongcat;
	delete base;
	delete rightcat;

}
