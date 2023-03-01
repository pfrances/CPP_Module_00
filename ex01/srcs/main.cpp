/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:12:44 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/01 11:09:50 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"

std::string	cleanLine( std::string line ) {
	size_t	i = 0;

	while (isspace(line[i])) {
		i++;
	}
	line.erase(0, i);
	if (line.empty())
		return (line);
	i = line.length();
	while (i > 0 && isspace(line[i - 1])) {
		i--;
	}
	line.erase(i);
	i = 0;
	while (line[i] != '\0') {
		if (isspace(line[i]) && isspace(line[i + 1])) {
			line.erase(i, 1);
		}
		else {
			i++;
		}
	}
	return (line);
}

int main( int argc, char *argv[]) {
	std::string	buff;
	PhoneBook	MyPhoneBook;

	(void)argv;
	if (argc > 1) {
		std::cout << "This program take any argument." << std::endl;
		return (1);
	}
	while (true) {
		std::cout << "Enter a command:" << std::endl << " > ";

		if (!std::getline(std::cin, buff)) {
			std::cout << "	EOF encountered. Exiting." << std::endl;
			return (2);
		}
		buff = cleanLine(buff);
		if (buff == "EXIT") {
			return (0) ;
		}
		else if (buff == "ADD") {
			if (!MyPhoneBook.addContact())
				return (3) ;
		}
		else if (buff == "SEARCH") {
			if (!MyPhoneBook.searchContact())
				return (4) ;
		}
		else {
			std::cout << "	Invalid command." << std::endl;
		}

		std::cout << std::endl;
	}
}

