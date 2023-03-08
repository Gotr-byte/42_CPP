/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:12:27 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/10 10:44:39 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {
	
	public:
	
	int		publicFoo;

	Sample ( void );
	~Sample ( void );
	
	void	publicBar( void ) const;

	private:

	int		_privateFoo;

	void	_privateBar( void ) const;
};
#endif