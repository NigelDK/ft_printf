/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:26:55 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/14 13:42:05 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*ft_ifree(int **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}
