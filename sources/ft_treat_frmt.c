/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_frmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:01:33 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/11 16:16:31 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_frmt_arg(va_list *args, t_flags *flags)
{
	if (flags->frmt == 'c')
		return (ft_treat_c(args, flags));
	else if (flags->frmt == 's')
		return (ft_treat_s(args, *flags));
	else if (flags->frmt == 'p')
		return (ft_treat_p(args, *flags));
	else if (flags->frmt == 'd' || flags->frmt == 'i')
		return (ft_treat_di(args, *flags));
	else if (flags->frmt == 'u')
		return (ft_treat_u(args, *flags));
	else if (flags->frmt == 'x' || flags->frmt == 'X')
		return (ft_treat_xx(args, *flags));
	else if (flags->frmt == '%')
		return (ft_treat_pct(*flags));
	return (NULL);
}

char		*ft_treat_frmt(const char *str, int *pos, va_list *args,
							t_flags *flags)
{
	ft_get_flags(str, pos, args, flags);
	return (ft_frmt_arg(args, flags));
}
