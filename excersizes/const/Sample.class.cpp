/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:12:23 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/09 17:44:23 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//c++ -std=c++98 -Wall -Wextra -Werror main.cpp Sample.class.cpp main.cpp -o const

#include <iostream>
#include "Sample.class.hpp"

Sample::Sample( float const f ) : pi ( f ), qd( 42 ){
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample( void ){
	std::cout << "Detructor called" << std::endl;
	return;
}

void Sample::bar( void )const {
	std::cout << "this->pl = " << this->pi << std::endl;
	std::cout << "this->qd = " << this->qd << std::endl;
	
	this->qd = 0;
	return;
}