/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:52:44 by nde-koni          #+#    #+#             */
/*   Updated: 2020/11/14 21:54:39 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlen_null(char **s, t_flags flags)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (s[0][len])
		len++;
	while (flags.loc[i] != -1)
		s[0][flags.loc[i++]] = '\0';
	return (len);
}
