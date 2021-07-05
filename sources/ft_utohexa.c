/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utohexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:14:27 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/15 12:14:29 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nr_len(unsigned nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

char		*ft_utohexa(unsigned nbr, int i)
{
	char		*buff;
	char		*set;
	int			len;

	if (!i)
		set = "0123456789abcdef";
	else
		set = "0123456789ABCDEF";
	len = ft_nr_len(nbr);
	if (!(buff = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nbr == 0)
		buff[0] = '0';
	buff[len--] = '\0';
	while (nbr > 0)
	{
		buff[len--] = set[nbr % 16];
		nbr = nbr / 16;
	}
	return (buff);
}
