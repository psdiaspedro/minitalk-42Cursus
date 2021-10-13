/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 12:50:02 by paugusto          #+#    #+#             */
/*   Updated: 2021/08/31 08:46:01 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = ft_vprintf(args, format);
	va_end(args);
	return (len);
}

int	ft_vprintf(va_list args, const char *format)
{
	int			len;
	t_format	*fmt;

	fmt = ft_init_format(args, format);
	while (fmt->format[fmt->i])
	{
		if (fmt->format[fmt->i] == '%')
			ft_placeholder(fmt);
		else
		{
			fmt->len += write(1, &fmt->format[fmt->i], 1);
			fmt->i++;
		}
	}
	len = fmt->len;
	free(fmt);
	return (len);
}
