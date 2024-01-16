/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:11:12 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/16 20:26:30 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed dummy(10);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "------------------------------------------------" << std::endl;

	std::cout << "Operator + : "<< Fixed(Fixed(5) + Fixed(10)) << std::endl;
	std::cout << "Operator - : "<< Fixed(Fixed(5) - Fixed(10)) << std::endl;
	std::cout << "Operator / : "<< Fixed(Fixed(10) / Fixed(5)) << std::endl;
	std::cout << "Operator * : "<< Fixed(Fixed(5) * Fixed(10)) << std::endl;

	std::cout << "------------------------------------------------" << std::endl;

	std::cout << "Operator ++ pre : "<< ++dummy << std::endl;
	std::cout << "Operator ++ post : "<< dummy++ << " Value = " << dummy <<std::endl;
	std::cout << "Operator -- pre : "<< --dummy << std::endl;
	std::cout << "Operator -- post : "<< dummy-- << " Value = " << dummy <<std::endl;

	std::cout << "------------------------------------------------" << std::endl;

	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;

	std::cout << "------------------------------------------------" << std::endl;

	std::cout << "Max " << "[" << a << ", " << b << "] : " << Fixed::max(a, b) << std::endl;
	std::cout << "Min " << "[" << a << ", " << b << "] : " << Fixed::min(a, b) << std::endl;
}
