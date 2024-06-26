/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:23:38 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 14:10:19 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

//awk '{print $2}'

Account::Account( int deposit ) 
	:  _accountIndex( _nbAccounts ), _amount( deposit ),
		_nbDeposits( 0 ), _nbWithdrawals( 0 ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_totalAmount += deposit;
	_nbAccounts++;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	_nbAccounts--;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";

	_totalNbDeposits++;
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;

	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	
	if (withdrawal > _amount) {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const {
	return (1);
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t		currentTime;
	std::tm*		localTime;
	char			timeBuffer[80];

	// Get the current time
	currentTime = std::time(NULL);
	// Convert the current time to the local time
	localTime = std::localtime(&currentTime);
	// Format the local time as a string
	std::strftime(timeBuffer, sizeof(timeBuffer), "[%Y%m%d_%H%M%S] ", localTime);
	// Print the formatted time
	std::cout << timeBuffer;
}
