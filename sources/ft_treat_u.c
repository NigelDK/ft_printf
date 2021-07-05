/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:59:54 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/14 17:31:45 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_treat_widthzero(char *argu, t_flags flags)
{
	char	*add_buff;
	char	*rtn;
	int		i;

	i = flags.width - ft_strlen(argu);
	if (!flags.minus)
	{
		add_buff = ft_buff_zero(i);
		rtn = ft_strjoin(add_buff, argu);
	}
	else
	{
		add_buff = ft_buff_space(i);
		rtn = ft_strjoin(argu, add_buff);
	}
	ft_free(&add_buff);
	return (rtn);
}

static void	ft_check_prec(char *argu, t_flags flags, char **rtn)
{
	char	*buff;
	char	*add_buff;
	int		i;

	if (flags.precwidth > (int)ft_strlen(argu))
	{
		i = flags.precwidth - (int)ft_strlen(argu);
		add_buff = ft_buff_zero(i);
		buff = ft_strjoin(add_buff, argu);
		ft_free(&add_buff);
		i = flags.width - flags.precwidth;
	}
	else
	{
		buff = ft_strjoin("\0", argu);
		i = flags.width - (int)ft_strlen(argu);
	}
	add_buff = ft_buff_space(i);
	if (flags.minus)
		*rtn = ft_strjoin(buff, add_buff);
	else
		*rtn = ft_strjoin(add_buff, buff);
	ft_free(&add_buff);
	ft_free(&buff);
}

static char	*ft_treat_width(char *argu, t_flags flags)
{
	char	*rtn;

	if (flags.width > (int)ft_strlen(argu))
		ft_check_prec(argu, flags, &rtn);
	else
		rtn = ft_strjoin("\0", argu);
	return (rtn);
}

static char	*ft_treat_precision(char *argu, t_flags flags)
{
	char	*width_buff;
	char	*rtn;
	int		i;

	if (flags.precwidth > (int)ft_strlen(argu))
	{
		i = flags.precwidth - (int)ft_strlen(argu);
		if (!(width_buff = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		width_buff[i--] = '\0';
		while (i >= 0)
			width_buff[i--] = '0';
		rtn = ft_strjoin(width_buff, argu);
		ft_free(&width_buff);
	}
	else
		rtn = ft_strjoin("\0", argu);
	return (rtn);
}

char		*ft_treat_u(va_list *args, t_flags flags)
{
	char *argu;
	char *rtn;

	if (!(argu = ft_utoa(va_arg(*args, unsigned long))))
		return (NULL);
	if (argu[0] == '0' && flags.precision)
		argu[0] = '\0';
	if (flags.zero && flags.width > (int)ft_strlen(argu) && !flags.precision)
		rtn = ft_treat_widthzero(argu, flags);
	else if (flags.width && flags.width > flags.precwidth)
		rtn = ft_treat_width(argu, flags);
	else if (flags.precision)
		rtn = ft_treat_precision(argu, flags);
	else
		rtn = ft_strjoin("\0", argu);
	ft_free(&argu);
	return (rtn);
}
