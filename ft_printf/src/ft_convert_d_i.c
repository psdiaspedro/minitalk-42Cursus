/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 08:42:21 by paugusto          #+#    #+#             */
/*   Updated: 2021/08/31 14:36:00 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_convert_d_i(t_format *fmt, t_holder *holder)
{
	int	arg;

	arg = va_arg(fmt->args, int);
	holder->argument = ft_itoa(arg);
	holder->len = ft_strlen(holder->argument);
}
