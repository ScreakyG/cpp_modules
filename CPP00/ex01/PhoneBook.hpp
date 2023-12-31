/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:11:57 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/23 23:12:00 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		bool	addContact(void);
		bool	printSearch(void);

	private:
		Contact	_contact_tab[8];
		int		_nbContact;
		void	_printHeader() const;
		void	_printBookContacts(std::string str, bool seperator) const;
		bool	_printIndexPrompt(void) const;
		bool	_verifyIndex(const std::string& str) const;
};

#endif