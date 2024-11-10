/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:09:10 by osarikay          #+#    #+#             */
/*   Updated: 2024/11/06 12:18:00 by osarikay         ###   ########.fr       */
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

int main()
{
    PhoneBook phoneBook;
    Contact contact;
    int index = 0;

    clearConsole();
    while (true)
    {
        std::cout << "\033[1;32mWelcome to the phonebook!" << std::endl;
        std::cout << "Please enter commands: ADD, SEARCH or EXIT\033[0m" << std::endl;
        if (std::cin.eof())
            break;
        std::string command;
        std::cin >> command;
        std::transform(command.begin(), command.end(), command.begin(), ::toupper);
        if (command == "ADD")
        {
            clearConsole();
            std::cout << "\033[1;36mAdding a new contact." << std::endl;
            usleep(280000);
            clearConsole();
            std::cout << "Adding a new contact.." << std::endl;
            usleep(280000);
            clearConsole();
            std::cout << "Adding a new contact...\033[0m" << std::endl;
            usleep(280000);
            clearConsole();
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
            phoneBook.contacts[index] = contact;
            index++;
        }
        else if (command == "SEARCH")
        {
            std::cout << "Searching for a contact..." << std::endl;
            // sleep(1);
            clearConsole();
            std::cout << "     index|first name| last name|  nickname" << std::endl;
            for (int i = 0; i < 8; i++) // burada boş gelen indexleri yazdırmamak gerekiyor | boş indexlerin kontrolü yapılmalı | 
            // ve boş olan indexler için index alanı yazdırılmamalı kaç tane kişi varsa o kadar kişi yazdırılmalı
            {
                if (phoneBook.contacts[i].getFirstName().length() == 0)
                    continue;
                std::cout << "----------|----------|----------|-----------" << std::endl;
                std::cout << std::setw(10);
                std::cout << i + 1 << "|";
                printShortened(phoneBook.contacts[i].getFirstName());
                std::cout << "|";
                printShortened(phoneBook.contacts[i].getLastName());
                std::cout << "|";
                printShortened(phoneBook.contacts[i].getNickname());
                std::cout << std::endl;
            }
                std::cout << "----------|----------|----------|-----------" << std::endl;
                std::string input;
                std::cout << "Enter the index of the contact you want to see: ";
                std::cin >> input;
                if (input.length() == 1 && isdigit(input[0]))
                {
                    int index = input[0] - '0';
                    if (index > 0 && index < 9 && phoneBook.contacts[index - 1].getFirstName().length() != 0)
                    {
                        clearConsole();
                        std::cout << "First name: " << phoneBook.contacts[index - 1].getFirstName() << std::endl;
                        std::cout << "Last name: " << phoneBook.contacts[index - 1].getLastName() << std::endl;
                        std::cout << "Nickname: " << phoneBook.contacts[index - 1].getNickname() << std::endl;
                        std::cout << "Phone number: " << phoneBook.contacts[index - 1].getPhoneNumber() << std::endl;
                        std::cout << "Darkest secret: " << phoneBook.contacts[index - 1].getDarkestSecret() << std::endl;
                    }
                    else if (index > 0 && index < 9 && phoneBook.contacts[index - 1].getFirstName().length() == 0)
                    {
                        clearConsole();
                        std::cout << "\033[1;31mThis contact is empty\033[0m" << std::endl;
                        usleep(1000000);
                    }
                }
                else
                {
                    clearConsole();
                    std::cout << "\033[1;31mInvalid input. Please enter a number between 1 and 8.\033[0m" << std::endl;
                    usleep(1000000);
                }
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting the phonebook..." << std::endl;
            break;
        }
        else
        {
            clearConsole();
            std::cout << "\033[1;31mInvalid command. Please enter ADD, SEARCH or EXIT\033[0m" << std::endl;
            usleep(1000000);
            clearConsole();
        }
    }
    return 0;
}