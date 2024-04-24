/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:44:54 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/24 15:17:48 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.h"
//# include "Data.hpp"
# include <stdint.h>

class Serializer
{
	public:
		static uintptr_t	serialize(Data*);
		static Data			*deserialize(uintptr_t);
};

#endif