/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_strpct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:42:47 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/11 16:16:59 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isflag(char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "0123456789-.*\0";
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_treat_strpct(const char *str, int *pos, va_list *args,
							t_flags *flags)
{
	int		i;

	i = 0;
	(*pos)++;
	while (str[(*pos) + i] == ' ')
		i++;
	while (ft_isflag(str[(*pos) + i]))
		i++;
	if (!ft_in_frmtset(str[(*pos) + i]))
		(*pos) = (*pos) + i;
	else if (ft_in_frmtset(str[(*pos) + i]))
	{
		flags->frmt = str[(*pos) + i];
		return (ft_treat_frmt(str, pos, args, flags));
	}
	return (NULL);
}
