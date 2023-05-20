/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:13:03 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/04 20:01:04 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"


PhoneBook::PhoneBook( void ) : _index(), _empty(true), _oldest(){}
PhoneBook::~PhoneBook( void ){}

Contact &PhoneBook::GetContact( int index ){
	return(PhoneBook::contact[index]);
}

void PhoneBook::add()
{
	std::string inputFirstName;
	std::string inputLastName;
	std::string inputNickname;
	std::string inputPhoneNumber;
	std::string inputDarkestSecret;

	if (_index > 7)
	{
		_index = _oldest;
        _oldest++;
        if (_oldest == 8)
            _oldest = 0;
	}
	ASK_FOR_PARAM(inputFirstName, "first name", _index);
	ASK_FOR_PARAM(inputLastName, "last name", _index);
	ASK_FOR_PARAM(inputNickname, "nickname", _index);
	ASK_FOR_PARAM(inputPhoneNumber, "phone number", _index);
	ASK_FOR_PARAM(inputDarkestSecret, "darkest secret", _index);
	this->contact[_index].SetName(inputFirstName);
	this->contact[_index].SetLastName(inputLastName);
	this->contact[_index].SetNickname(inputNickname);
	this->contact[_index].SetPhoneNumber(inputPhoneNumber);
	this->contact[_index].SetDarkestSecret(inputDarkestSecret);
	_index++;
	_empty = false;
}

void PhoneBook::search()
{
	int localIndex = 0;
	if (_empty == true)
	{
		std::cout << "no contacts in database" << std::endl;
		return ;
	}
	while (localIndex < 8)
	{
		std::string firstNameToPrint;
		std::string lastNameToPrint;
		std::string nicknameToPrint;
		std::string phoneNumberToPrint;
		if (this->GetContact(localIndex).GetName().length() > 10)
			firstNameToPrint = this->GetContact(localIndex).GetName().substr(0, 9).append(".");
		else
			firstNameToPrint = this->GetContact(localIndex).GetName().substr(0, 10);
		if (this->GetContact(localIndex).GetLastName().length() > 10)
			lastNameToPrint = this->GetContact(localIndex).GetLastName().substr(0, 9).append(".");
		else
			lastNameToPrint = this->GetContact(localIndex).GetLastName().substr(0, 10);
		if (this->GetContact(localIndex).GetNickname().length() > 10)
			nicknameToPrint = this->GetContact(localIndex).GetNickname().substr(0, 9).append(".");
		else
			nicknameToPrint = this->GetContact(localIndex).GetLastName().substr(0, 10);
		if (this->GetContact(localIndex).GetPhoneNumber().length() > 10)
			phoneNumberToPrint = this->GetContact(localIndex).GetPhoneNumber().substr(0, 9).append(".");
		else
			phoneNumberToPrint = this->GetContact(localIndex).GetPhoneNumber().substr(0, 10);
		std::cout << std::setw(10) << localIndex << " | ";
		std::cout << std::setw(10) << firstNameToPrint << " | ";
		std::cout << std::setw(10) << lastNameToPrint << " | ";
		std::cout << std::setw(10) << nicknameToPrint.substr(0, 10) << " | ";
		std::cout << std::setw(10) << phoneNumberToPrint.substr(0, 10) << std::endl;
		localIndex++;
	}
	std::string searchPrompt = "enter entry id nb: ";
	std::cout << searchPrompt;
	std::string inputQueryIndex;
	std::getline(std::cin,  inputQueryIndex);
	int queryIndex = (inputQueryIndex[0] - 48);
	if (inputQueryIndex[1])
		queryIndex = -1;
	if (queryIndex > 7 || queryIndex  < 0 || !inputQueryIndex[0] ||
    !(this->GetContact(queryIndex).GetName()[0]))
	{
		std::cout << "invalid entry" << std::endl;
		return ;
	}
	std::string fullFistName = this->GetContact(queryIndex).GetName();
	std::string fullLastName = this->GetContact(queryIndex).GetLastName();
	std::string fullNickname = this->GetContact(queryIndex).GetNickname();
	std::string fullPhoneNumber = this->GetContact(queryIndex).GetPhoneNumber();
	std::string fullDarkSecret = this->GetContact(queryIndex).GetDarkSecret();
	std::cout << "recovering full data: " << std::endl;
	std::cout << "name: " << fullFistName << std::endl;
	std::cout << "last name: " << fullLastName << std::endl;
	std::cout << "nick: " << fullNickname << std::endl;
	std::cout << "phone number: " << fullPhoneNumber << std::endl;
	std::cout << "dark secret: " << fullDarkSecret << std::endl;
}