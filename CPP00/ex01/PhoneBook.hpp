/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:12:04 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/04 19:26:22 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

#define ASK_FOR_PARAM(param, name, index) \
std::cout << "Please enter " << name << ": ";\
std::getline(std::cin,  param); \
if (!param[0]) \
    return;


class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();

    Contact &GetContact(int index);
    void    add();
    void    search();
private:
    Contact contact[8];
    int     _index;
    bool    _empty;
    int     _oldest;
};

