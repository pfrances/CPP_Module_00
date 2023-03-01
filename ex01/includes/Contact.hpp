/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:09:53 by pfrances          #+#    #+#             */
/*   Updated: 2023/02/28 12:43:25 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "includes.hpp"

class Contact {

public:
				Contact(void);
				~Contact(void);

	std::string	getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickName( void ) const;
	std::string	getPhoneNumber( void ) const;
	std::string	getDarkestSecret( void ) const;

	bool		initContact( void );

private:
	std::string	_FirstName;
	std::string	_LastName;
	std::string	_NickName;
	std::string	_PhoneNumber;
	std::string	_DarkestSecret;

	bool		_setFirstName( void );
	bool		_setLastName( void );
	bool		_setNickName( void );
	bool		_setPhoneNumber( void );
	bool		_setDarkestSecret( void );

};

#endif