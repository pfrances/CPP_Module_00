/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:49:21 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/01 11:09:42 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"

PhoneBook::PhoneBook( void ) : _MyContacts_index(0), _MyContacts_nb(0) {
	//std::cout << "PhoneBook: Constructor called " << std::endl;
	return ;
}

PhoneBook::~PhoneBook( void ) {
	//std::cout << "PhoneBook: Destructor called " << std::endl;
	return ;
}

bool	PhoneBook::addContact( void ) {
	if (!this->_MyContacts[this->_MyContacts_index].initContact())
		return (false);
	this->_MyContacts_index = (this->_MyContacts_index + 1) % CONTACT_MAX;
	if (this->_MyContacts_nb < CONTACT_MAX) {
		this->_MyContacts_nb++;
	}
	return (true);
}

std::string	truncateString(const std::string& str, unsigned int width) {
	if (str.length() > width) {
		return str.substr(0, width - 1) + ".";
	} else {
		return str;
	}
}

void	PhoneBook::_showContactOverview( void ) const {

	std::cout << "Index     |First name|Last name |Nickname  " << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;

	for (int i = 0; i < this->_MyContacts_nb; i++) {

		std::cout << std::right << std::setw(10) << i << "|"
		<< std::right << std::setw(10) << truncateString(this->_MyContacts[i].getFirstName(), 10) << "|"
		<< std::right << std::setw(10) << truncateString(this->_MyContacts[i].getLastName(), 10) << "|"
		<< std::right << std::setw(10) << truncateString(this->_MyContacts[i].getNickName(), 10)
		<< std::endl;
	}
	std::cout << "----------|----------|----------|----------" << std::endl;
}

int PhoneBook::_askContactIndex() const {
	int index;

	while (true) {
		std::cout << "Enter the index of the contact to display:" << std::endl << " > ";

		if (std::cin >> index) {
			if (index < 0 || index >= this->_MyContacts_nb) {
				std::cout << "Invalid index." << std::endl;
			} else {
				break ;
			}
		} else {
			if (std::cin.eof()) {
				std::cout << "	EOF encountered. Exiting." << std::endl;
				index = -1;
				break ;
			} else {
				std::cout << "Invalid input. Please enter a valid integer." << std::endl;
			}
		}
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}

	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');

	return (index);
}

bool	PhoneBook::_showSingleContactInfo( void ) const {

	int	index;

	index = this->_askContactIndex();
	if (index < 0 || index >= this->_MyContacts_nb) {
		return (false);
	}

	std::cout << "First name: " << this->_MyContacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_MyContacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_MyContacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->_MyContacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_MyContacts[index].getDarkestSecret() << std::endl;

	return (true);
}

bool	PhoneBook::searchContact( void ) const {

	if (this->_MyContacts_nb == 0) {
		std::cout << "	No Contact set yet." << std::endl;
		return (true);
	}
	this->_showContactOverview();
	if (!this->_showSingleContactInfo())
		return (false);
	return (true);

}
