/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:30:58 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/10 11:06:08 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//c++ -Wextra -Werror -Wall main.cpp Sample.class.cpp
#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( void ){
	std::cout << "Constructor called" << std::endl;
	this->publicFoo = 0;
	std::cout << "this->publicFoo: 	" << this->publicFoo << std::endl;
	this->_privateFoo = 0;
	std::cout << "this->_privateFoo: " << this->_privateFoo << std::endl;

	this->publicBar();
	this->_privateBar();

	return;
}

Sample::~Sample( void ){
	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::publicBar( void ) const {
	std::cout << "Member function publicBar called";
	return;
}

void Sample::_privateBar( void ) const {
	std::cout << "Member function _privateBar called" << std::endl;
	return;
}
