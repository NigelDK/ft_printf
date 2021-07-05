/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:24:50 by nde-koni          #+#    #+#             */
/*   Updated: 2020/12/08 10:24:52 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_treat_str(const char *str, int *pos)
{
	char	*buff;
	int		i;

	i = 0;
	while (str && str[(*pos) + i] && str[(*pos) + i] != '%')
	{
		i++;
	}
	if (!(buff = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str && str[*pos] && str[*pos] != '%')
	{
		buff[i] = str[*pos];
		(*pos)++;
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
