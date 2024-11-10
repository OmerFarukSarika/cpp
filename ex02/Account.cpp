#include "Account.hpp"
#include <iostream>

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
    std::cout << "accounts:" << Account::getNbAccounts << ";total:" << Account::_totalNbWithdrawals <<  ";deposits:" << Account::getNbDeposits << ";withdrawals:" << Account::getNbWithdrawals << std::endl;
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
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << std::endl;
    this->_amount += deposit;
    Account::_nbDeposits++;
    Account::_totalNbDeposits += deposit;
    this->_totalAmount += deposit;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits;
}

bool Account::makeWithdrawal( int withdrawal ){
    
}