/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:04:54 by fgonzale          #+#    #+#             */
/*   Updated: 2024/01/16 20:30:42 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Fixed::Fixed(void) : _nbEntier(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(const int number) : _nbEntier(number << _bits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number) : _nbEntier(roundf(number * (1 << _bits)))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Fixed& Fixed::operator=(Fixed const & rhs)
{
	//std::cout << "Copy assignement operator called" << std::endl;
	if (this != &rhs)
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

bool Fixed::operator>(Fixed const & rhs) const
{
	if (this->_nbEntier > rhs._nbEntier)
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const & rhs) const
{
	if (this->_nbEntier < rhs._nbEntier)
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	if (this->_nbEntier >= rhs._nbEntier)
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	if (this->_nbEntier <= rhs._nbEntier)
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const & rhs) const
{
	if (this->_nbEntier == rhs._nbEntier)
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	if (this->_nbEntier != rhs._nbEntier)
		return (true);
	return (false);
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++(void) // Pre-incrementation
{
	this->_nbEntier++;
	return (*this);
}

Fixed Fixed::operator++(int) // Post-incrementation
{
	Fixed save(*this);
	this->_nbEntier++;
	return (save);
}

Fixed& Fixed::operator--(void) // Pre-decrementation
{
	this->_nbEntier--;
	return (*this);
}

Fixed Fixed::operator--(int) // Post-decrementation
{
	Fixed save(*this);
	this->_nbEntier--;
	return (save);
}

std::ostream & operator<<(std::ostream & output, Fixed const & input)
{
	output << input.toFloat();
	return (output);
}

/******************************************************************************/
/*								OTHER FUNCTIONS								  */
/******************************************************************************/

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a <= b)
		return (a);
	return (b);
}
