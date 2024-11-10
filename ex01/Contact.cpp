/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:09:17 by osarikay          #+#    #+#             */
/*   Updated: 2024/11/06 12:09:18 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName()
{
    return this->firstName;
}

std::string Contact::getLastName()
{
    return this->lastName;
}

std::string Contact::getNickname()
{
    return this->nickname;
}

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}