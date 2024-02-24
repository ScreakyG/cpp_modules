/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:05:15 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/24 19:22:56 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		~MateriaSource(void);
		MateriaSource& operator=(const MateriaSource& src);

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

	private:

		AMateria* _inventory[4];
};

#endif
