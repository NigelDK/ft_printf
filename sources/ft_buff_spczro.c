/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_spczro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:47:29 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/15 11:47:32 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_buff_space(int i)
{
	char	*buff;

	if (i < 0)
		return (NULL);
	if (!(buff = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	buff[i--] = '\0';
	while (i >= 0)
		buff[i--] = ' ';
	return (buff);
}

char	*ft_buff_zero(int i)
{
	char	*buff;

	if (i < 0)
		return (NULL);
	if (!(buff = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	buff[i--] = '\0';
	while (i >= 0)
		buff[i--] = '0';
	return (buff);
}
