/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_frmtset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:23:11 by nde-koni          #+#    #+#             */
/*   Updated: 2020/12/07 19:23:13 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_in_frmtset(char c)
{
	char	*set;
	int		i;

	i = 0;
	set = "cspdiuxX%\0";
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
