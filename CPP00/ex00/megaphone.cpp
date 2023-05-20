/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:29:53 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/05 17:55:52 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (argc > 1)
	{
		j = 1;
		while(argv[j])
		{
			i = 0;
			while(argv[j][i])
				std::cout << (char)toupper(argv[j][i++]);
			j++;
		}
		std::cout << std::endl;
	}
  return 0;	
}