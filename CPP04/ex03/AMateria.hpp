/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:52:49 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/24 17:15:58 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:

		AMateria(void);
		AMateria(const AMateria& src);
		virtual ~AMateria(void);
		AMateria& operator=(const AMateria& src);

		AMateria(std::string const & type);

		std::string const & getType() const; // Returns the materia type.

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:

		std::string _type;
};

#endif
