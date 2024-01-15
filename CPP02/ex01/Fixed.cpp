/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:04:54 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/15 20:57:26 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) : _nbEntier(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int number) : _nbEntier(number << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _nbEntier(roundf(number * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_nbEntier = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbEntier);
}

void Fixed::setRawBits(int const raw)
{
	this->_nbEntier = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	return (float)_nbEntier / (1 << _bits);
}

int Fixed::toInt(void) const
{
	return (_nbEntier >> _bits);
}

std::ostream & operator<<(std::ostream & output, Fixed const & input)
{
	output << input.toFloat();
	return (output);
}
