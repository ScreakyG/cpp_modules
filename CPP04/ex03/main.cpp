/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:24:07 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/25 23:14:17 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"

void materiaSourceTests()
{
	std::cout << "####### MATERIASOURCE TESTS #######" << std::endl;
	std::cout << std::endl;

	std::cout << "<-----Learning Materia----->" << std::endl;
	std::cout << std::endl;
	MateriaSource *src = new MateriaSource();

	if (!src)
		return ;
	src->learnMateria(NULL);
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	src->showRecipes();


	std::cout << std::endl;
	std::cout << "<-----Materia DeepCopy----->" << std::endl;
	std::cout << std::endl;

	MateriaSource *srcCopy = new MateriaSource(*src);
	if (!srcCopy)
	{
		delete src;
		return ;
	}
	srcCopy->showRecipes();

	src->learnMateria(new Cure());


	std::cout << "Copy : " << std::endl;
	srcCopy->showRecipes();

	std::cout << "OG : " << std::endl;
	src->showRecipes();
	delete srcCopy;


	std::cout << std::endl;
	std::cout << "<-----Inventory Overflow----->" << std::endl;
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	std::cout << std::endl;
	std::cout << "<-----Creating Materia----->" << std::endl;
	std::cout << std::endl;

	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	AMateria* error = src->createMateria("error");

	if (ice)
		std::cout << "Materia type for *ice = " << ice->getType() << std::endl;
	else
		std::cout << "Error malloc materia" << std::endl;

	if (cure)
		std::cout << "Materia type for *cure = " << cure->getType() << std::endl;
	else
		std::cout << "Error malloc materia" << std::endl;

	if (!error)
		std::cout << "Error malloc materia" << std::endl;

	if (ice)
		delete ice;
	if (cure)
		delete cure;

	delete src;

	std::cout << std::endl;
	std::cout << "#############################" << std::endl;
	std::cout << std::endl;
}

void charactersTests()
{
	std::cout << "####### CHARACTERS TESTS #######" << std::endl;
	std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	if (!src)
		return ;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;
	std::cout << "<-----Creating Character----->" << std::endl;
	std::cout << std::endl;

	Character *lewis = new Character("Lewis");
	if (!lewis)
	{
		delete src;
		return ;
	}

	std::cout << std::endl;
	std::cout << "<-----Equip Character----->" << std::endl;
	std::cout << std::endl;

	AMateria *m1 = src->createMateria("cure");
	AMateria *m2 = src->createMateria("ice");
	AMateria *m3 = src->createMateria("ice");

	if (!m1)
	{
		delete src;
		delete lewis;
		delete m2;
		delete m3;
		return ;
	}
	if (!m2)
	{
		delete src;
		delete lewis;
		delete m1;
		delete m3;
		return ;
	}
	if (!m3)
	{
		delete src;
		delete lewis;
		delete m1;
		delete m2;
		return ;
	}

	lewis->equip(NULL);
	lewis->equip(m1);
	lewis->equip(m2);

	lewis->showInventory();

	std::cout << std::endl;
	std::cout << "<-----Character Copy----->" << std::endl;
	std::cout << std::endl;

	Character *lewisCopy = new Character(*lewis);
	if (!lewisCopy)
	{
		delete src;
		delete lewis;
		delete m3;
		return ;
	}
	lewisCopy->showInventory();
	std::cout << "##Copy name = " << lewisCopy->getName() << std::endl;
	lewis->equip(m3);
	std::cout << "##Copy inventory won't change##" << std::endl;
	lewisCopy->showInventory();

	delete lewisCopy;

	std::cout << std::endl;
	std::cout << "<-----More than 4 items----->" << std::endl;
	std::cout << std::endl;

	AMateria *m4 = src->createMateria("ice");
	AMateria *m5 = src->createMateria("cure");

	if (!m4)
	{
		delete src;
		delete lewis;
		delete m5;
		return ;
	}

	if (!m5)
	{
		delete src;
		delete lewis;
		delete m4;
		return ;
	}

	lewis->equip(m4); // Equip at slot 3.
	lewis->equip(m5); // Can't equip , stays on the ground.
	lewis->showInventory();

	std::cout << std::endl;
	std::cout << "<-----Unequip items----->" << std::endl;
	std::cout << std::endl;

	lewis->unequip(-1);
	lewis->unequip(3); // m4 unequiped.
	lewis->showInventory();

	std::cout << "unequiped does not delete it : " << m4->getType() << std::endl;


	std::cout << std::endl;
	std::cout << "<-----Delete MateriaSource and Character----->" << std::endl;
	std::cout << std::endl;

	delete src;
	delete lewis;


	std::cout << std::endl;
	std::cout << "<-----Delete ground items----->" << std::endl;
	std::cout << std::endl;

	delete m5;
	delete m4;

	std::cout << "############################" << std::endl;
	std::cout << std::endl;
}

void subjectTests(void)
{
	std::cout << "####### SUBJECT TEST #######" << std::endl;
	std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	if (!src)
		return ;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	if (!me)
	{
		delete src;
		return ;
	}

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	if (!bob)
	{
		delete src;
		delete me;
		return ;
	}

	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
	std::cout << "######################" << std::endl;
	std::cout << std::endl;
}

int main()
{
	subjectTests();
	materiaSourceTests();
	charactersTests();
}
