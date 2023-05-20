/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:23:19 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/02 15:34:11 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		Contact( void );
		~Contact( void );
		void SetName( std::string name );
		void SetLastName(std::string inputLastName);
		void SetNickname(std::string inputNickname);
		void SetPhoneNumber(std::string inputPhoneNumber);
		void SetDarkestSecret(std::string inputDarkestSecret);
		std::string GetName(void);
		std::string GetLastName(void);
		std::string GetNickname(void);
		std::string GetPhoneNumber(void);
		std::string GetDarkSecret(void);
		void Search(std::string firstName);
};
