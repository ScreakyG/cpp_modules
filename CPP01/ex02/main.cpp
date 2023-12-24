/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:56:21 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/24 15:33:36 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Adresse string en memoire : " << &str << std::endl;
	std::cout << "Adresse stockee dans stringPTR : " << stringPTR << std::endl;
	std::cout << "Adresse stockee dans stringREF : " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Valeur de la string : "<<str << std::endl;
	std::cout << "Valeur pointee par stringPTR : " << *stringPTR << std::endl;
	std::cout << "Valeur pointee par stringREF : " << stringREF << std::endl;
	return (0);
}