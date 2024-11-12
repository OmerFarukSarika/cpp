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

int main()
{
    PhoneBook phoneBook;
    Contact contact;
    int index;

    index = 0;
    phoneBook.clearConsole();
    while (true)
    {
        std::cout << "\033[1;32mWelcome to the phonebook!" << std::endl;
        std::cout << "Please enter commands: ADD, SEARCH or EXIT\033[0m" << std::endl;
        if (std::cin.eof())
            break;
        std::string command;
        std::cin >> command;
        if (command == "ADD")
        {
            phoneBook.addContact();
        }
        else if (command == "SEARCH")
        {
            phoneBook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting the phonebook..." << std::endl;
            break;
        }
        else
        {
            phoneBook.clearConsole();
            std::cout << "\033[1;31mInvalid command. Please enter ADD, SEARCH or EXIT\033[0m" << std::endl;
            usleep(1000000);
            phoneBook.clearConsole();
        }
    }
    return 0;
}