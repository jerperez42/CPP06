/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:25:41 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/24 16:04:31 by jerperez         ###   ########.fr       */
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

void	identify(Base* p)
{
	Base* tmp;
	tmp = dynamic_cast<A*>(p);
	if (tmp)
	{
		std::cout << "identify(Base* p): info: found A" << std::endl;
		return ;
	}
	tmp = dynamic_cast<B*>(p);
	if (tmp)
	{
		std::cout << "identify(Base* p): info: found B" << std::endl;
		return ;
	}
	tmp = dynamic_cast<C*>(p);
	if (tmp)
	{
		std::cout << "identify(Base* p): info: found C" << std::endl;
		return ;
	}
}

void	identify(Base& p)
{

	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "identify(Base& p): info: found A" << std::endl;
	}
	catch (const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "identify(Base& p): info: found B" << std::endl;
	}
	catch (const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "identify(Base& p): info: found C" << std::endl;
	}
	catch (const std::exception& e) {}
}

int main(void)
{
	Base	*unknown = generate();
	identify(unknown);
	identify(*unknown);
	delete unknown;
}