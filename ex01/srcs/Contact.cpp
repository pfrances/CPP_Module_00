/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:49:21 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/01 11:09:29 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"

Contact::Contact( void ) {
	//std::cout << "Contact: Constructor called " << std::endl;
	return ;
}

Contact::~Contact( void ) {
	//std::cout << "Contact: Destructor called " << std::endl;
	return ;
}

bool	Contact::initContact( void ) {
	if (!Contact::_setFirstName())
		return (false);
	if (!Contact::_setLastName())
		return (false);
	if (!Contact::_setNickName())
		return (false);
	if (!Contact::_setPhoneNumber())
		return (false);
	if (!Contact::_setDarkestSecret())
		return (false);
	return (true);
}

bool	Contact::_setFirstName( void ) {
	std::string	buff;

	while (true) {
		std::cout << "Enter the contact's first name : ";

		if (!std::getline(std::cin, buff)) {
			std::cout << "	EOF encountered. Exiting." << std::endl;
			return (false);
		}
		buff = cleanLine(buff);
		if (!buff.empty()) {
			this->_FirstName = buff;
			return (true);
		}
	}
}

bool	Contact::_setLastName( void ) {
	std::string	buff;

	while (true) {
		std::cout << "Enter the contact's last name : ";

		if (!std::getline(std::cin, buff)) {
			std::cout << "	EOF encountered. Exiting." << std::endl;
			return (false);
		}
		buff = cleanLine(buff);
		if (!buff.empty()) {
			this->_LastName = buff;
			return (true);
		}
	}
}

bool	Contact::_setNickName( void ) {
	std::string	buff;

	while (true) {
		std::cout << "Enter the contact's nickname : ";

		if (!std::getline(std::cin, buff)) {
			std::cout << "	EOF encountered. Exiting." << std::endl;
			return (false);
		}
		buff = cleanLine(buff);
		if (!buff.empty()) {
			this->_NickName = buff;
			return (true);
		}
	}
}

bool	Contact::_setPhoneNumber( void ) {
	std::string	buff;

	while (true) {
		std::cout << "enter the contact's phone number : ";

		if (!std::getline(std::cin, buff)) {
			std::cout << "	EOF encountered. Exiting." << std::endl;
			return (false);
		}
		buff = cleanLine(buff);
		if (!buff.empty()) {
			this->_PhoneNumber = buff;
			return (true);
		}
	}
}

bool	Contact::_setDarkestSecret( void ) {
	std::string	buff;

	while (true) {
		std::cout << "Enter the contact's darkest secret : ";

		if (!std::getline(std::cin, buff)) {
			std::cout << "	EOF encountered. Exiting." << std::endl;
			return (false);
		}
		buff = cleanLine(buff);
		if (!buff.empty()) {
			this->_DarkestSecret = buff;
			return (true);
		}
	}
}

std::string Contact::getFirstName( void ) const {
	return (Contact::_FirstName);
}

std::string Contact::getLastName( void ) const {
	return (Contact::_LastName);
}

std::string Contact::getNickName( void ) const {
	return (Contact::_NickName);
}

std::string Contact::getPhoneNumber( void ) const {
	return (Contact::_PhoneNumber);
}

std::string Contact::getDarkestSecret( void ) const {
	return (Contact::_DarkestSecret);
}
