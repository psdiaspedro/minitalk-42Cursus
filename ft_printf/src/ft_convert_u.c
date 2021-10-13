/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 08:43:50 by paugusto          #+#    #+#             */
/*   Updated: 2021/08/31 16:12:44 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_convert_u(t_format *fmt, t_holder *holder, char *base)
{
	unsigned int	nbr;
	char			*ptr;

	nbr = (unsigned int)va_arg(fmt->args, unsigned int);
	ptr = ft_itoa_base((unsigned long)nbr, base);
	holder->argument = ft_strdup(ptr);
	free(ptr);
	holder->len = ft_strlen(holder->argument);
}
