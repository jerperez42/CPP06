/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:05:31 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/24 15:17:00 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	Data		*data_ptr;
	uintptr_t	ptr;

	data.id = 42;
	data.patates = 3;
	std::cout << "Data: .id=" << data.id << "  .patates=" << data.patates << std::endl;
	ptr = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(ptr);
	std::cout << "ptr: ->id=" << data_ptr->id << " ->patates=" << data_ptr->patates << std::endl;
}