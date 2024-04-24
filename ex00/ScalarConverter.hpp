/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:45:35 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/24 14:12:09 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		static void			display(std::string, std::string, std::string, std::string);
		static void			display(void);
		static bool			isChar(const std::string&);
		static bool			isInt(const std::string&);
		static bool			isFloat(const std::string&);
		static bool			isDouble(const std::string&);
		static void			convertFromChar(const std::string&);
		static void			convertFromInt(const std::string&);
		static void			convertFromFloat(const std::string&);
		static void			convertFromDouble(const std::string&);
		static std::string	toStr(float);
		static std::string	toStr(double);
		static char			_c;
		static int			_i;
		static float		_f;
		static double		_d;
	public:
		static void	convert(const std::string&);
};

#endif