/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:01:19 by nde-koni          #+#    #+#             */
/*   Updated: 2020/11/26 17:04:28 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_getnbr(const char *str, int *pos)
{
	int		i;
	char	*nbr_buff;

	i = 0;
	while (ft_isdigit(str[(*pos) + i]))
		i++;
	nbr_buff = ft_substr(str, *pos, i);
	while (ft_isdigit(str[*pos]))
		(*pos)++;
	(*pos)--;
	i = ft_atoi(nbr_buff);
	ft_free(&nbr_buff);
	return (i);
}
