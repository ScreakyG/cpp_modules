/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:24:07 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/24 22:00:52 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");
	AMateria* tmp = src->createMateria("ice");
	AMateria* tmp2 = src->createMateria("ice");

	me->equip(tmp);
	me->equip(tmp2);

	delete me;
	delete src;
}
