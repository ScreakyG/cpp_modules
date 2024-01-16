/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:02:34 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/16 20:07:13 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed(void); // Canonical , constructeur default.
		Fixed(const int number);
		Fixed(const float number);
		Fixed(Fixed const & src); // Canonical , construtceur de recopie.
		~Fixed(void); // Canonical , deconstructeur.

		float toFloat(void) const;
		int	  toInt(void) const;
		Fixed& operator=(Fixed const & rhs); // Canonical , operateur assignement.
		int getRawBits(void) const;
		void setRawBits(int const raw);


		bool operator>(Fixed const & rhs) const;
		bool operator<(Fixed const & rhs) const;
		bool operator>=(Fixed const & rhs) const;
		bool operator<=(Fixed const & rhs) const;
		bool operator==(Fixed const & rhs) const;
		bool operator!=(Fixed const & rhs) const;

		Fixed operator*(Fixed const & rhs) const;
		Fixed operator+(Fixed const & rhs) const;
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);

		static Fixed& max (Fixed &a, Fixed &b);
		static Fixed& min (Fixed &a, Fixed &b);
		static const Fixed& max(Fixed const & a, Fixed const & b);
		static const Fixed& min(Fixed const &a, Fixed const &b);

	private:
		int _nbEntier;
		static const int _bits;
};

std::ostream& operator<<(std::ostream & ouput, Fixed const & input);

#endif
