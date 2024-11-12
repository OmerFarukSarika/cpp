/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:09:24 by osarikay          #+#    #+#             */
/*   Updated: 2024/11/06 12:09:25 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <unistd.h>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <algorithm>

void clearConsole() {
    std::cout << "\033[2J\033[H";
}

void printShortened(const std::string& input) {

    if (input.length() == 0) {
        std::cout << std::setw(11);
    }
    else if (input.length() > 9) {
        for (int i = 0; i < 9; ++i) {
            std::cout << input[i];
        }
        std::cout << ".";
    } 
    else {
        std::cout << std::setw(10);
        std::cout << input;
    }
}

void PhoneBook::addContact() {
    Contact contact;
    if (index == 8) {
        std::cout << "Phonebook is full!" << std::endl;
        return;
    }
    this->clearConsole();
    std::cout << "\033[1;36mAdding a new contact." << std::endl;
    usleep(280000);
    this->clearConsole();
    std::cout << "Adding a new contact.." << std::endl;
    usleep(280000);
    this->clearConsole();
    std::cout << "Adding a new contact...\033[0m" << std::endl;
    usleep(280000);
    this->clearConsole();
    std::cout << "\033[1;37mEnter your first name: ";
    std::string name;
    std::cin >> name;
    contact.setFirstName(name);
    std::cout << "Enter your last name: ";
    std::string lastName;
    std::cin >> lastName;
    contact.setLastName(lastName);
    std::cout << "Enter your nickname: ";
    std::string nickname;
    std::cin >> nickname;
    contact.setNickname(nickname);
    std::cout << "Enter your phone number: ";
    std::string phoneNumber;
    std::cin >> phoneNumber;
    contact.setPhoneNumber(phoneNumber);
    std::cout << "Enter your darkest secret: ";
    std::string darkestSecret;
    std::cin >> darkestSecret;
    std::cout << "\033[0m";
    contact.setDarkestSecret(darkestSecret);
    contacts[index] = contact;
    index++;
}

void PhoneBook::searchContact(){
        std::cout << "Searching for a contact..." << std::endl;
        // sleep(1);
        this->clearConsole();
        std::cout << "     index|first name| last name|  nickname" << std::endl;
        for (int i = 0; i < 8; i++) // burada boş gelen indexleri yazdırmamak gerekiyor | boş indexlerin kontrolü yapılmalı | 
        // ve boş olan indexler için index alanı yazdırılmamalı kaç tane kişi varsa o kadar kişi yazdırılmalı
        {
            if (this->contacts[i].getFirstName().length() == 0)
                continue;
            std::cout << "----------|----------|----------|-----------" << std::endl;
            std::cout << std::setw(10);
            std::cout << i + 1 << "|";
            printShortened(this->contacts[i].getFirstName());
            std::cout << "|";
            printShortened(this->contacts[i].getLastName());
            std::cout << "|";
            printShortened(this->contacts[i].getNickname());
            std::cout << std::endl;
        }
            std::cout << "----------|----------|----------|-----------" << std::endl;
            std::string input;
            std::cout << "Enter the index of the contact you want to see: ";
            std::cin >> input;
            if (input.length() == 1 && isdigit(input[0]))
            {
                int index = input[0] - '0';
                if (index > 0 && index < 9 && this->contacts[index - 1].getFirstName().length() != 0)
                {
                    this->clearConsole();
                    std::cout << "First name: " << this->contacts[index - 1].getFirstName() << std::endl;
                    std::cout << "Last name: " << this->contacts[index - 1].getLastName() << std::endl;
                    std::cout << "Nickname: " << this->contacts[index - 1].getNickname() << std::endl;
                    std::cout << "Phone number: " << this->contacts[index - 1].getPhoneNumber() << std::endl;
                    std::cout << "Darkest secret: " << this->contacts[index - 1].getDarkestSecret() << std::endl;
                }
                else if (index > 0 && index < 9 && this->contacts[index - 1].getFirstName().length() == 0)
                {
                    this->clearConsole();
                    std::cout << "\033[1;31mThis contact is empty\033[0m" << std::endl;
                    sleep(1000000);
                }
            }
            else
            {
                this->clearConsole();
                std::cout << "\033[1;31mInvalid input. Please enter a number between 1 and 8.\033[0m" << std::endl;
                usleep(1000000);
            }
}