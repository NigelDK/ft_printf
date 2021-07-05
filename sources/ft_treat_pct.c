/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:12:02 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/14 11:59:13 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_treat_widthleft(char *argu, t_flags flags)
{
	char	*buff;
	int		i;

	i = 1;
	if (!(buff = malloc(sizeof(char) * (flags.width + 1))))
		return (NULL);
	buff[0] = argu[0];
	while (i < flags.width)
	{
		buff[i] = ' ';
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

static char	*ft_treat_widthright(char *argu, t_flags flags)
{
	char	*buff;
	int		i;

	i = flags.width;
	if (!(buff = malloc(sizeof(char) * (flags.width + 1))))
		return (NULL);
	buff[i--] = '\0';
	buff[i--] = argu[0];
	if (flags.zero)
	{
		while (i >= 0)
			buff[i--] = '0';
	}
	else if (!flags.zero)
	{
		while (i >= 0)
			buff[i--] = ' ';
	}
	return (buff);
}

char		*ft_treat_pct(t_flags flags)
{
	char	*argu;
	char	*rtn;

	argu = "%\0";
	if (flags.minus && flags.width)
		rtn = ft_treat_widthleft(argu, flags);
	else if (!flags.minus && flags.width)
		rtn = ft_treat_widthright(argu, flags);
	else
		rtn = ft_strjoin("\0", argu);
	return (rtn);
}
