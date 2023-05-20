/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:21:51 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/04 10:30:11 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"

Contact::Contact( void ){
	// std::cout << "Contact Constructor called" << std::endl;
	return;
}

Contact::~Contact( void ){
	// std::cout << "Contact Destructor called" << std::endl;
	return;
}

void Contact::SetName( std::string name ){
			Contact::firstName = name;
}

void Contact::SetLastName ( std::string inputLastName){
			Contact::lastName = inputLastName;
}

void Contact::SetNickname ( std::string inputNickname){
			Contact::nickname = inputNickname;
}

void Contact::SetPhoneNumber ( std::string inputPhoneNumber){
			Contact::phoneNumber = inputPhoneNumber;
}

void Contact::SetDarkestSecret(std::string inputDarkestSecret){
			Contact::darkestSecret = inputDarkestSecret;
}

std::string Contact::GetName(void){
	return(Contact::firstName);
}

std::string Contact::GetLastName(void){
	return(Contact::lastName);
}

std::string Contact::GetNickname(void){
	return(Contact::nickname);
}

std::string Contact::GetPhoneNumber(void){
	return(Contact::phoneNumber);
}

std::string Contact::GetDarkSecret(void){
	return(Contact::darkestSecret);
}