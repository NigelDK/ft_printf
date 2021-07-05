/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:40:37 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/15 15:34:14 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_ulltohexa(unsigned long long nbr)
{
	unsigned long long	nbr2;
	char				*buff;
	char				*set;
	int					count;

	nbr2 = nbr;
	count = 0;
	set = "0123456789abcdef";
	while (nbr2 > 0)
	{
		nbr2 = nbr2 / 16;
		count++;
	}
	if (!(buff = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	buff[count--] = '\0';
	while (nbr > 0)
	{
		buff[count--] = set[nbr % 16];
		nbr = nbr / 16;
	}
	return (buff);
}

static char	*ft_treat_widthleft(char *argu, t_flags flags)
{
	char	*width_buff;
	char	*rtn;
	int		i;

	if (flags.width > (int)ft_strlen(argu))
	{
		i = flags.width - (int)ft_strlen(argu);
		if (!(width_buff = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		width_buff[i--] = '\0';
		while (i >= 0)
			width_buff[i--] = ' ';
		rtn = ft_strjoin(argu, width_buff);
		ft_free(&width_buff);
	}
	else
		rtn = ft_strjoin("\0", argu);
	return (rtn);
}

static char	*ft_treat_widthright(char *argu, t_flags flags)
{
	char	*width_buff;
	char	*rtn;
	int		i;

	if (flags.width > (int)ft_strlen(argu))
	{
		i = flags.width - (int)ft_strlen(argu);
		if (!(width_buff = malloc(sizeof(char) * (i + 1))))
			return (NULL);
		width_buff[i--] = '\0';
		while (i >= 0)
			width_buff[i--] = ' ';
		rtn = ft_strjoin(width_buff, argu);
		ft_free(&width_buff);
	}
	else
		rtn = ft_strjoin("\0", argu);
	return (rtn);
}

char		*ft_treat_p(va_list *args, t_flags flags)
{
	char	*argu;
	char	*zerox;
	char	*rtn;
	void	*adr;

	adr = va_arg(*args, void *);
	if (adr == NULL)
		if (flags.precision)
			zerox = "0x";
		else
			zerox = "0x0";
	else
		zerox = "0x";
	if (!(rtn = ft_ulltohexa((unsigned long long)adr)))
		return (NULL);
	argu = ft_strjoin(zerox, rtn);
	ft_free(&rtn);
	if (flags.minus && flags.width)
		rtn = ft_treat_widthleft(argu, flags);
	else if (!flags.minus && flags.width)
		rtn = ft_treat_widthright(argu, flags);
	else
		rtn = ft_strjoin("\0", argu);
	ft_free(&argu);
	return (rtn);
}
