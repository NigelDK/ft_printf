/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:42:00 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/15 11:42:03 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_str_insert(char *s1, char *s2, int i)
{
	char	*buff;
	int		len_b;
	int		pos;

	if (!s1 || !s2)
		return (NULL);
	pos = 0;
	len_b = ft_strlen(s1) + ft_strlen(s2);
	if (!(buff = malloc(sizeof(char) * (len_b + 1))))
		return (NULL);
	while (pos < i)
		buff[pos++] = *s1++;
	while (s2 && *s2)
		buff[pos++] = *s2++;
	while (s1 && *s1)
		buff[pos++] = *s1++;
	buff[pos] = '\0';
	return (buff);
}
