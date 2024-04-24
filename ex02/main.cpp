/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:25:41 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/24 15:40:51 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	const int	idk = 42;
	int			random_value = (uintptr_t)(&idk) % 3;

	std::cout << "generate: info: new " << static_cast<char>('A' + random_value) << std::endl;
	if (0 == random_value)
		return (new A);
	else if (1 == random_value)
		return (new B);
	else if (2 == random_value)
		return (new C);
	return (0);
}

int main(void)
{
	Base	*unknown = generate();
	delete unknown;
}