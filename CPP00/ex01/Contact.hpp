/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:10:53 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/23 23:10:56 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>

# define GREEN "\033[32m"
# define RESET "\033[0m"

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		bool		fillContact(void);
		void		printInfos(void) const;
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);

	private:
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string	_PhoneNumber;
		std::string _Secret;
		bool	fill_infos(std::string msg, std::string *variable);
};

#endif
