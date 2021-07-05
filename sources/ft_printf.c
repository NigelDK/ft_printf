/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 18:48:11 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/14 13:46:29 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_init_struct(t_flags *flags)
{
	if (!(flags->loc = (int *)malloc(sizeof(int) * 2)))
		return (-1);
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->precwidth = 0;
	flags->spc = 0;
	flags->star = 0;
	flags->c_loc = 0;
	flags->loc[0] = -1;
	flags->loc[1] = -1;
	flags->frmt = '0';
	return (0);
}

void		ft_reset_struct(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->precwidth = 0;
	flags->spc = 0;
	flags->star = 0;
	flags->frmt = '0';
}

static char	*ft_check_str(char *str, va_list *args, t_flags *flags, char **buff)
{
	char	*add_buff;
	char	*tmp;
	int		pos;

	pos = 0;
	while (str && str[pos])
	{
		if (str[pos] == '%')
		{
			if (!(add_buff = ft_treat_strpct(str, &pos, args, flags)))
				return (ft_free(buff));
			pos++;
		}
		else
			add_buff = ft_treat_str(str, &pos);
		tmp = *buff;
		*buff = ft_strjoin(*buff, add_buff);
		ft_free(&tmp);
		ft_free(&add_buff);
		flags->c_loc = ft_strlen(*buff);
		ft_reset_struct(flags);
	}
	return (*buff);
}

static int	ft_get_len(char **buff, t_flags flags)
{
	int	len;

	if (flags.loc[0] != -1)
		len = ft_strlen_null(buff, flags);
	else
		len = ft_strlen(*buff);
	return (len);
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	flags;
	char	*buff;
	int		len;

	if (!str || !*str)
		return (0);
	if (!(buff = malloc(sizeof(char))))
		return (-1);
	buff[0] = '\0';
	if (ft_init_struct(&flags) == -1)
		return (-1);
	va_start(args, str);
	if (!(buff = ft_check_str((char *)str, &args, &flags, &buff)))
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	len = ft_get_len(&buff, flags);
	write(1, buff, len);
	ft_free(&buff);
	ft_ifree(&flags.loc);
	return (len);
}
