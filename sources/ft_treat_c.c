/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 10:06:22 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/14 18:19:22 by nde-koni         ###   ########.fr       */
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

static int	ft_intjoin(t_flags *flags)
{
	int	*arr;
	int	*tmp;
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (flags->loc[i] != -1)
		i++;
	if (!(arr = malloc(sizeof(int) * (i + 2))))
		return (0);
	while (flags->loc[j] != -1)
	{
		arr[j] = flags->loc[j];
		j++;
	}
	if (!flags->minus)
		arr[j++] = flags->c_loc + flags->width - 1;
	else
		arr[j++] = flags->c_loc;
	arr[j] = -1;
	tmp = flags->loc;
	flags->loc = arr;
	ft_ifree(&tmp);
	return (1);
}

static int	ft_replc_null(char **argu, t_flags *flags)
{
	argu[0][0] = 'a';
	(flags->width == 0) ? (flags->width = 1) : (0);
	if (flags->loc[0] == -1)
	{
		if (!flags->minus)
			flags->loc[0] = flags->c_loc + flags->width - 1;
		else
			flags->loc[0] = flags->c_loc;
	}
	else
	{
		if (!(ft_intjoin(flags)))
		{
			ft_free(argu);
			ft_ifree(&flags->loc);
			return (0);
		}
	}
	return (1);
}

char		*ft_treat_c(va_list *args, t_flags *flags)
{
	char	*argu;
	char	*rtn;

	if (!(argu = malloc(sizeof(char) * 2)))
		return (NULL);
	argu[0] = va_arg(*args, int);
	argu[1] = '\0';
	if (argu[0] == '\0')
		if (!(ft_replc_null(&argu, flags)))
			return (NULL);
	if (flags->minus && flags->width)
		rtn = ft_treat_widthleft(argu, *flags);
	else if (!flags->minus && flags->width)
		rtn = ft_treat_widthright(argu, *flags);
	else
		return (argu);
	ft_free(&argu);
	return (rtn);
}
