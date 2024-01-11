/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:02:34 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/11 20:31:13 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed(void); // Canonical , constructeur default.
		Fixed(Fixed const & src); // Canonical , construtceur de recopie.
		~Fixed(void); // Canonical , deconstructeur.

		Fixed& operator=(Fixed const & rhs); // Canonical , operateur assignement.
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _nbEntier;
		static const int _bits;
};

std::ostream& operator<<(std::ostream & ouput, Fixed const & input);

#endif
