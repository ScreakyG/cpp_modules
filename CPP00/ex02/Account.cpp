#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account:: _totalAmount = 0;
int	Account:: _totalNbDeposits = 0;
int	Account:: _totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount; 
	std::cout << ";created";
	std::cout << std::endl;
	_nbAccounts++;
	_totalAmount += this->_amount;
}

Account::~Account(void)
{
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed";
	std::cout << std::endl;
}

void Account::displayAccountsInfos(void)
{
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void Account::displayStatus(void) const
{
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << ";ammount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;	
	if (withdrawal > checkAmount())
	{
		std::cout << ";withdrawal: refused";
		std::cout << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << ";ammount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

int Account::checkAmount(void) const 
{
	return (this->_amount);
}

// void Account::_displayTimestamp(void)
// {

// }
