/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 14:40:40 by nde-koni          #+#    #+#             */
/*   Updated: 2021/01/14 13:42:17 by nde-koni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		precwidth;
	int		star;
	int		spc;
	int		c_loc;
	int		*loc;
	char	frmt;
}				t_flags;

int				ft_printf(const char *str, ...);
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_frmt_c(const char *s0, const char *s1, const char s2);
char			*ft_free(char **s);
char			*ft_ifree(int **s);
int				ft_getnbr(const char *str, int *pos);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *nptr);
int				ft_isdigit(char c);
void			ft_get_flags(const char *str, int *pos, va_list *args,
								t_flags *flags);
char			*ft_treat_c(va_list *args, t_flags *flags);
char			*ft_treat_s(va_list *args, t_flags flags);
char			*ft_treat_p(va_list *args, t_flags flags);
char			*ft_treat_di(va_list *args, t_flags flags);
char			*ft_treat_u(va_list *args, t_flags flags);
char			*ft_treat_xx(va_list *args, t_flags flags);
char			*ft_treat_frmt(const char *str, int *pos, va_list *args,
								t_flags *flags);
int				ft_in_frmtset(char c);
char			*ft_treat_strpct(const char *str, int *pos, va_list *args,
									t_flags *flags);
char			*ft_treat_str(const char *str, int *pos);
char			*ft_treat_pct(t_flags flags);
char			*ft_itoa(int n);
size_t			ft_strlen_null(char **s, t_flags flags);
char			*ft_str_insert(char *s1, char *s2, int i);
char			*ft_buff_space(int i);
char			*ft_buff_zero(int i);
char			*ft_utoa(unsigned int nr);
char			*ft_utohexa(unsigned nbr, int i);

#endif
