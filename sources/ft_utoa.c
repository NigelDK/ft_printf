/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:09:26 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/15 12:09:27 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nr_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_utoa(unsigned int nr)
{
	char		*str;
	int			i;

	i = ft_nr_len(nr);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (nr == 0)
	{
		str[i] = 48;
		return (str);
	}
	while (nr > 0)
	{
		str[i--] = 48 + (nr % 10);
		nr /= 10;
	}
	return (str);
}
