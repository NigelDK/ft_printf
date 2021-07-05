/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:46:14 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/11 15:39:23 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_width_buff(char **width_buff, int i)
{
	width_buff[0][i--] = '\0';
	while (i >= 0)
		width_buff[0][i--] = ' ';
}

static char	*ft_treat_widthleft(char *argu, t_flags flags)
{
	char	*width_buff;
	char	*rtn;
	int		i;
	int		free;

	free = 0;
	if (flags.precision && flags.precwidth < (int)ft_strlen(argu))
	{
		argu = ft_substr(argu, 0, flags.precwidth);
		free = 1;
	}
	if (flags.width > (int)ft_strlen(argu))
	{
		i = flags.width - (int)ft_strlen(argu);
		if (!(width_buff = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		ft_width_buff(&width_buff, i);
		rtn = ft_strjoin(argu, width_buff);
		ft_free(&width_buff);
	}
	else
		rtn = ft_strjoin("\0", argu);
	(free) ? (ft_free(&argu)) : (0);
	return (rtn);
}

static char	*ft_fill_width(int i, t_flags flags)
{
	char	*width_buff;

	if (!(width_buff = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	width_buff[i--] = '\0';
	if (flags.zero)
	{
		while (i >= 0)
			width_buff[i--] = '0';
	}
	else if (!flags.zero)
	{
		while (i >= 0)
			width_buff[i--] = ' ';
	}
	return (width_buff);
}

static char	*ft_treat_widthright(char *argu, t_flags flags)
{
	char	*width_buff;
	char	*rtn;
	int		i;
	int		free;

	free = 0;
	if (flags.precision && flags.precwidth < (int)ft_strlen(argu))
	{
		argu = ft_substr(argu, 0, flags.precwidth);
		free = 1;
	}
	if (flags.width > (int)ft_strlen(argu))
	{
		i = flags.width - (int)ft_strlen(argu);
		width_buff = ft_fill_width(i, flags);
		rtn = ft_strjoin(width_buff, argu);
		ft_free(&width_buff);
	}
	else
		rtn = ft_strjoin("\0", argu);
	if (free)
		ft_free(&argu);
	return (rtn);
}

char		*ft_treat_s(va_list *args, t_flags flags)
{
	char	*argu;
	char	*rtn;

	argu = va_arg(*args, char *);
	if (!argu)
		argu = "(null)";
	if (flags.minus && (flags.width || flags.precision))
		rtn = ft_treat_widthleft(argu, flags);
	else if (!flags.minus && (flags.width || flags.precision))
		rtn = ft_treat_widthright(argu, flags);
	else
		rtn = ft_strjoin("\0", argu);
	return (rtn);
}
