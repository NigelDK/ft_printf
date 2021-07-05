/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:15:08 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/11 16:15:33 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_isdigit_nozero(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	return (0);
}

static void	ft_star(va_list *args, t_flags *flags)
{
	flags->star = 1;
	if (!flags->precision)
		flags->width = va_arg(*args, int);
	else if (flags->precision)
		flags->precwidth = va_arg(*args, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width = flags->width * -1;
	}
	(flags->precwidth < 0) ? (flags->precision = 0) : (0);
}

void		ft_get_flags(const char *str, int *pos, va_list *args,
							t_flags *flags)
{
	(str[*pos] == ' ') ? (flags->spc = 1) : (0);
	while (str[*pos] == ' ')
		(*pos)++;
	while (!ft_in_frmtset(str[*pos]))
	{
		if (str[*pos] == '-')
			flags->minus = 1;
		else if (str[*pos] == '0')
		{
			(str[*pos - 1] == '.') ? (flags->precwidth = 0) : (0);
			(str[*pos - 1] == '.') ? (0) : (flags->zero = 1);
		}
		else if (str[*pos] == '.')
			flags->precision = 1;
		else if (str[*pos] == '*')
			ft_star(args, flags);
		else if (ft_isdigit_nozero(str[*pos]))
		{
			if (!flags->precision)
				flags->width = ft_getnbr(str, pos);
			else if (flags->precision)
				flags->precwidth = ft_getnbr(str, pos);
		}
		(*pos)++;
	}
}
