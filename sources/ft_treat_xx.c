/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_xx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 23:53:15 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/14 11:56:49 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_treat_widthzero(char *argu, t_flags flags)
{
	char	*tmp;
	char	*rtn;
	int		i;

	i = flags.width - ft_strlen(argu);
	tmp = ft_buff_zero(i);
	if (!flags.minus)
		rtn = ft_strjoin(tmp, argu);
	else
		rtn = ft_strjoin(argu, tmp);
	ft_free(&tmp);
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

char		*ft_treat_xx(va_list *args, t_flags flags)
{
	char *argu;
	char *rtn;

	if (flags.frmt == 'x')
		if (!(argu = ft_utohexa(va_arg(*args, unsigned), 0)))
			return (NULL);
	if (flags.frmt == 'X')
		if (!(argu = ft_utohexa(va_arg(*args, unsigned), 1)))
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
