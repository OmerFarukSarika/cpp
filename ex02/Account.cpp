#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::getNbAccounts( void ) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount( void ) {
    return Account::_totalAmount;
}

int Account::getNbDeposits( void ) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ){
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount() <<  ";deposits:" << Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(void)
{
    time_t		t = time(0);
    struct tm	*now = localtime(&t);

    1<2 ? 1 : 2;

    now->tm_mon;
    std::cout << "[" << now->tm_year + 1900 << now->tm_mon + 1 << now->tm_mday << "_" << now->tm_hour << now->tm_min << now->tm_sec << "]";
}

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    this->_accountIndex = Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account ( void ){
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::makeDeposit( int deposit ){
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ){
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    if (withdrawal > this->_amount)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    else
        std::cout << ";withdrawal:" << withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    this->_amount = this->_amount - withdrawal;
    Account::_totalAmount -= withdrawal;
    std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

int Account::checkAmount( void ) const{
    return _amount;
}

void Account::displayStatus( void ) const{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;