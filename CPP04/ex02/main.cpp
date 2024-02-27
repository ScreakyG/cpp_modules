/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:00:56 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/27 16:52:52 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

static void deepCopyTests(void)
{
	std::cout << "#################DEEP COPY##################" << std::endl;

	Cat cat;
	std::cout << "<**************************>" << std::endl;
	{
		Cat temp = cat;
		std::cout << "<**************************>" << std::endl;
	}
	std::cout << "<**************************>" << std::endl;
}

static void subjectTests(void)
{
	std::cout << "#################SUBJECT TEST##################" << std::endl;

	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	if (dog)
		dog->makeSound();
	if (cat)
		cat->makeSound();

	delete dog;
	delete cat;
}

static void arrayTests(void)
{
	std::cout << "#################ARRAY TEST##################" << std::endl;

	AAnimal* array[20];
	int	i;

	for (i = 0; i < 20; i++)
	{
		if (i < 10)
			array[i] = new Cat();
		else
			array[i] = new Dog();
	}

	for (i = 0; i < 20; i++)
	{
		if (!array[i])
			std::cout << "Error with memory allocation at index : " << i << std::endl;
		else
			array[i]->makeSound();
	}

	for (i = 0; i < 20; i++)
		delete array[i];
}

static void ideasTests()
{

	std::cout << "#################IDEAS TEST##################" << std::endl;

	Dog* dog = new Dog();

	std::cout << "<---------------Dog ideas------------------->" << std::endl;

	if (dog)
	{
		dog->getBrain()->setIdeas(0, "I want to eat");
		dog->getBrain()->setIdeas(1, "I want to play");
		dog->getBrain()->printIdeas();
	}

	std::cout << "<---------------Creating copyDog------------->" << std::endl;

	Dog* copyDog = new Dog(*dog);

	std::cout << "<---------------copyDog ideas------------------->" << std::endl;

	if (copyDog)
		copyDog->getBrain()->printIdeas();

	std::cout << std::endl;
	std::cout << "<--Changing dog ideas should not change copyDog->" << std::endl;

	if (dog)
	{
		std::cout << "<----------------Dog new ideas-------------->" << std::endl;
		dog->getBrain()->setIdeas(0, "I dont want to eat");
		dog->getBrain()->setIdeas(1, "I dont want to play");
		dog->getBrain()->printIdeas();
		std::cout << "<-----------copyDog wont change ideas------->" << std::endl;
		copyDog->getBrain()->printIdeas();
	}

	std::cout << "<-------------------------------------------->" << std::endl;

	delete dog;
	delete copyDog;
}

int main()
{
	ideasTests();
	arrayTests();
	subjectTests();
	deepCopyTests();

	//AAnimal* test = new AAnimal();
}
