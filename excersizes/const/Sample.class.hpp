/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:07:49 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/09 17:10:00 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {
	public:
	
	float const pi;
	int			qd;
	
	Sample( float const f );
	~Sample( void );
	void	bar( void ) const;
};
#endif