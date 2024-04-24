/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:35 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/24 14:21:58 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarConverter.h"
#include <sstream>
#include <iostream>
#include <limits>

char		ScalarConverter::_c = '\0';
int			ScalarConverter::_i = 0;
float		ScalarConverter::_f = 0.0f;
double		ScalarConverter::_d = 0.0;

void	ScalarConverter::display(std::string c, std::string i, std::string f, std::string d)
{
	std::cout	<< "char: "		<< c << std::endl
				<< "int: " 		<< i << std::endl
				<< "float: " 	<< f << std::endl
				<< "double: " 	<< d << std::endl;
}

std::string	ScalarConverter::toStr(float f)
{
	std::stringstream	s;
	std::string			out;

	s << f;
	out = s.str();
	if (-1ul == out.find("."))
		out += ".0";
	out += "f";
	return (out);
}

std::string	ScalarConverter::toStr(double d)
{
	std::stringstream	s;
	std::string			out;

	s << d;
	out = s.str();
	if (-1ul == out.find("."))
		out += ".0";
	return (out);
}

void	ScalarConverter::display(void)
{
	const float			inff = std::numeric_limits<float>::infinity();
	const double		inf = std::numeric_limits<double>::infinity();


	std::cout << "char: ";
	if (CHAR_MIN > _i || CHAR_MAX < _i)
		std::cout << SC_IMP << std::endl;
	else if (' ' > _c || '~' < _c)
		std::cout << SC_NCH << std::endl;
	else
		std::cout << "'" << _c << "'" << std::endl;
	std::cout << "int: ";
	if (INT_MIN > _d || INT_MAX < _d)
		std::cout << SC_IMP << std::endl;
	else
		std::cout << _i << std::endl;
	std::cout << "float: ";
	if (inff == _f || -inff == _f)
		std::cout << SC_IMP << std::endl;
	else
		std::cout << ScalarConverter::toStr(_f) << std::endl;
	std::cout << "double: ";
	if (inf == _d || -inf == _d)
		std::cout << SC_IMP << std::endl;
	else
		std::cout << ScalarConverter::toStr(_d) << std::endl;
}

bool	ScalarConverter::isInt(const std::string &representation)
{
	size_t	len = representation.length();
	size_t	i;

	if (12 < len)
		return (false);
	i = 0;
	if ('-' == representation[i])
		i++;
	if ('0' == representation[i] && len != (1 + i))
		return (false);
	while (i < len)
	{
		if ('0' > representation[i] || '9' < representation[i])
			return (false);
		i++;
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string &representation)
{
	const size_t	len = representation.length();
	size_t			i;

	i = 0;
	if ('-' == representation[i])
		i++;
	if ('0' == representation[i] && len != (1 + i))
		return (false);
	while (len > i && '.' != representation[i])
	{
		if ('0' > representation[i] || '9' < representation[i])
			return (false);
		i++;
	}
	if (len == i ||  '.' != representation[i])
		return (false);
	i++;
	while (i < len && 'f' != representation[i])
	{
		if ('0' > representation[i] || '9' < representation[i])
			return (false);
		i++;
	}
	if (len == i ||  'f' != representation[i])
		return (false);
	i++;
	return (len == i);
}

bool	ScalarConverter::isDouble(const std::string &representation)
{
	const size_t	len = representation.length();
	size_t			i;

	i = 0;
	if ('-' == representation[i])
		i++;
	if ('0' == representation[i] && len != (1 + i))
		return (false);
	while (len > i && '.' != representation[i])
	{
		if ('0' > representation[i] || '9' < representation[i])
			return (false);
		i++;
	}
	if (len == i ||  '.' != representation[i])
		return (false);
	i++;
	while (i < len)
	{
		if ('0' > representation[i] || '9' < representation[i])
			return (false);
		i++;
	}
	return (true);
}

void	ScalarConverter::convertFromInt(const std::string &representation)
{
	std::stringstream	sin(representation);
	std::stringstream	scontrol;

	sin >> _i;
	scontrol << _i;
	if (representation != scontrol.str())
	{
		ScalarConverter::display(SC_IMP, SC_IMP, SC_IMP, SC_IMP);
		return ;
	}
	_c = static_cast<char>(_i);
	_f = static_cast<float>(_i);
	_d = static_cast<double>(_i);
	ScalarConverter::display();
}

void	ScalarConverter::convertFromFloat(const std::string &representation)
{
	std::stringstream	s(representation);

	s >> _f;
	if (FLT_MAX == _f || FLT_MIN == _f)
	{
		ScalarConverter::display(SC_IMP, SC_IMP, SC_IMP, SC_IMP);
		return ;
	}
	_c = static_cast<char>(_f);
	_i = static_cast<int>(_f);
	_d = static_cast<double>(_f);
	ScalarConverter::display();
}

void	ScalarConverter::convertFromDouble(const std::string &representation)
{
	std::stringstream	s(representation);

	s >> _d;
	if (DBL_MAX == _d || DBL_MIN == _d)
	{
		ScalarConverter::display(SC_IMP, SC_IMP, SC_IMP, SC_IMP);
		return ;
	}
	_c = static_cast<char>(_d);
	_i = static_cast<int>(_d);
	_f = static_cast<float>(_d);
	ScalarConverter::display();
}

void	ScalarConverter::convert(const std::string &representation)
{
	if ("" == representation)
		ScalarConverter::display(SC_IMP, SC_IMP, SC_IMP, SC_IMP);
	else if (std::string(SC_NINF) == representation || std::string(SC_NINFF) == representation)
		ScalarConverter::display(SC_IMP, SC_IMP, SC_NINFF, SC_NINF);
	else if (std::string(SC_PINF) == representation || std::string(SC_PINFF) == representation)
		ScalarConverter::display(SC_IMP, SC_IMP, SC_PINFF, SC_PINF);
	else if (std::string(SC_NAN) == representation || std::string(SC_NANF) == representation)
		ScalarConverter::display(SC_IMP, SC_IMP, SC_NANF, SC_NAN);
	else if (ScalarConverter::isInt(representation))
		ScalarConverter::convertFromInt(representation);
	else if (ScalarConverter::isFloat(representation))
		ScalarConverter::convertFromFloat(representation);
	else if (ScalarConverter::isDouble(representation))
		ScalarConverter::convertFromDouble(representation);
	else
		ScalarConverter::display(SC_IMP, SC_IMP, SC_IMP, SC_IMP);
}
