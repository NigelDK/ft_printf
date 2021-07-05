/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:58:11 by nde-koni          #+#    #+#             */
/*   Updated: 2020/11/24 11:58:49 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	unsigned int	nb;

	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	nb = 0;
	while (*nptr >= 48 && *nptr <= 57)
	{
		nb = (nb * 10) + *nptr - '0';
		nptr++;
	}
	return ((int)(nb * sign));
}
