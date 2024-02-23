/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:01:34 by fgonzale          #+#    #+#             */
/*   Updated: 2024/02/23 19:26:42 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& src);
		~Brain(void);
		Brain& operator=(const Brain& src);

		void setIdeas(int index, std::string str);
		void printIdeas(void) const;

	private:
		std::string _ideas[100];
};

#endif
