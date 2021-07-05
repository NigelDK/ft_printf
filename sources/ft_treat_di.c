/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 13:17:03 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/14 15:35:05 by nde-koni         ###   ########.fr       */
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
		if (argu[0] == '-')
			rtn = ft_str_insert(argu, add_buff, 1);
		else
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

static void	ft_fill_width(char *argu, t_flags flags, char **buff, int *i)
{
	char	*add_buff;

	if (flags.precwidth >= (int)ft_strlen(argu))
	{
		*i = flags.precwidth - (int)ft_strlen(argu);
		if (argu[0] == '-')
		{
			add_buff = ft_buff_zero((*i) + 1);
			*buff = ft_str_insert(argu, add_buff, 1);
			*i = flags.width - flags.precwidth - 1;
		}
		else
		{
			add_buff = ft_buff_zero(*i);
			*buff = ft_strjoin(add_buff, argu);
			*i = flags.width - flags.precwidth;
		}
		ft_free(&add_buff);
	}
	else
	{
		*buff = ft_strjoin("\0", argu);
		*i = flags.width - (int)ft_strlen(argu);
	}
}

static char	*ft_treat_width(char *argu, t_flags flags)
{
	char	*buff;
	char	*add_buff;
	char	*rtn;
	int		i;

	if (flags.width > (int)ft_strlen(argu))
	{
		ft_fill_width(argu, flags, &buff, &i);
		add_buff = ft_buff_space(i);
		if (flags.minus)
			rtn = ft_strjoin(buff, add_buff);
		else
			rtn = ft_strjoin(add_buff, buff);
		ft_free(&add_buff);
		ft_free(&buff);
	}
	else
		rtn = ft_strjoin("\0", argu);
	return (rtn);
}

static char	*ft_treat_precision(char *argu, t_flags flags)
{
	char	*add_buff;
	char	*rtn;
	int		i;

	if (flags.precwidth >= (int)ft_strlen(argu))
	{
		i = flags.precwidth - (int)ft_strlen(argu);
		if (argu[0] == '-')
		{
			add_buff = ft_buff_zero(i + 1);
			rtn = ft_str_insert(argu, add_buff, 1);
		}
		else
		{
			add_buff = ft_buff_zero(i);
			rtn = ft_strjoin(add_buff, argu);
		}
		ft_free(&add_buff);
	}
	else
		rtn = ft_strjoin("\0", argu);
	return (rtn);
}

char		*ft_treat_di(va_list *args, t_flags flags)
{
	char	*argu;
	char	*rtn;
	char	*tmp;

	if (!(argu = ft_itoa(va_arg(*args, int))))
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
	if (flags.spc)
	{
		tmp = rtn;
		rtn = ft_strjoin(" ", rtn);
		ft_free(&tmp);
	}
	return (rtn);
}
