/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:35:28 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/01 18:50:46 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) :	_accountIndex(_nbAccounts),
											_amount(initial_deposit),
											_nbDeposits(0),
											_nbWithdrawals(0) {

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<<"index:" << this->_accountIndex << ";"
				<<"amount:" << this->_amount << ";"
				<<"created" << std::endl;

}

Account::Account( void )  :	_accountIndex(_nbAccounts),
							_amount(0),
							_nbDeposits(0),
							_nbWithdrawals(0) {
	_nbAccounts++;
}

Account::~Account( void ) {

	_displayTimestamp();
	std::cout	<<"index:" << this->_accountIndex << ";"
				<<"amount:" << this->_amount << ";"
				<<"closed" << std::endl;

}

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {

	_displayTimestamp();
	std::cout	<<"accounts:" << _nbAccounts << ";"
				<<"total:" << _totalAmount << ";"
				<<"deposits:" << _totalNbDeposits << ";"
				<<"withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {

	int	old_amount = this->_amount;

	this->_nbDeposits++;
	_totalNbDeposits++;
	this->_amount += deposit;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout	<<"index:" << this->_accountIndex << ";"
				<<"p_amount:" << old_amount << ";"
				<<"deposit:" << deposit << ";"
				<<"amount:" << this->_amount << ";"
				<<"nb_deposits:" << this->_nbDeposits << std::endl;

}

bool	Account::makeWithdrawal( int withdrawal ) {

	if (this->_amount < withdrawal) {

		_displayTimestamp();
		std::cout	<<"index:" << this->_accountIndex << ";"
					<<"p_amount:" << this->_amount << ";"
					<<"withdrawal:" << "refused" << std::endl;

		return (false);
	}

	int	old_amount = this->_amount;

	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;

	_displayTimestamp();
	std::cout	<<"index:" << this->_accountIndex << ";"
				<<"p_amount:" << old_amount << ";"
				<<"withdrawal:" << withdrawal << ";"
				<<"amount:" << this->_amount << ";"
				<<"nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	return (true);
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {

	_displayTimestamp();
	std::cout	<<"index:" << this->_accountIndex << ";"
				<<"amount:" << this->_amount << ";"
				<<"deposits:" << this->_nbDeposits << ";"
				<<"withdrawals:" << this->_nbWithdrawals << std::endl;

}

void	Account::_displayTimestamp( void ) {

	std::ostringstream oss;
	std::time_t now = std::time(NULL);
	std::tm* timeinfo = std::localtime(&now);
	char buffer[80];

	std::strftime(buffer, 80, "%Y%m%d_%H%M%S", timeinfo);
	oss << "[" << buffer << "]";

	//std::cout << (oss.str()) << " ";
	std::cout << "[19920104_091532] ";
}
