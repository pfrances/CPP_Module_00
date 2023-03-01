/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:09:53 by pfrances          #+#    #+#             */
/*   Updated: 2023/02/28 13:48:17 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "includes.hpp"

class PhoneBook {

public:
			PhoneBook( void );
			~PhoneBook( void );
	bool	addContact( void );
	bool	searchContact( void ) const;

private:
	Contact	_MyContacts[CONTACT_MAX];
	int		_MyContacts_index;
	int		_MyContacts_nb;

	void	_showContactOverview( void ) const;
	int		_askContactIndex( void ) const;
	bool	_showSingleContactInfo( void ) const;
};

#endif