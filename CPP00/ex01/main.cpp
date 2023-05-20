/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:16:07 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/04 19:59:51 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

#define SAME 0

int main()
{
	PhoneBook company;
	std::string prompt = "$$$> ";
	std::string readInput;

	std::cout << prompt;
	while (std::getline(std::cin, readInput))
	{
		if (readInput == "ADD")
			company.add();
		else if (readInput == "EXIT")
			break;
		else if (readInput == "SEARCH")
			company.search();
		else
			std::cout << "invalid command" << std::endl;
		std::cout << "enter ADD, SEARCH or EXIT" << std::endl;
		std::cout << prompt;
	}
	return 0;
}