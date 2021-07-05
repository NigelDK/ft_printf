# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nde-koni <nde-koni@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/31 14:25:11 by nde-koni          #+#    #+#              #
#    Updated: 2020/11/27 10:42:36 by nde-koni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	sources/ft_strlen.c \
		sources/ft_strjoin.c \
		sources/ft_free.c \
		sources/ft_treat_str.c \
		sources/ft_getnbr.c \
		sources/ft_substr.c \
		sources/ft_atoi.c \
		sources/ft_isdigit.c \
		sources/ft_get_flags.c \
		sources/ft_treat_c.c \
		sources/ft_treat_s.c \
		sources/ft_treat_p.c \
		sources/ft_treat_di.c \
		sources/ft_treat_u.c \
		sources/ft_treat_xx.c \
		sources/ft_treat_frmt.c \
		sources/ft_in_frmtset.c \
		sources/ft_treat_strpct.c \
		sources/ft_treat_str.c \
		sources/ft_printf.c \
		sources/ft_treat_pct.c \
		sources/ft_itoa.c \
		sources/ft_buff_spczro.c \
		sources/ft_str_insert.c \
		sources/ft_utoa.c \
		sources/ft_utohexa.c

HEADER = includes/ft_printf.h

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR = ar rc


all:	$(NAME)

$(NAME):	$(OBJ)
	@echo "Making library"
	@$(AR) $(NAME) $(OBJ) $(HEADER)

%.o:	%.c
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing object files"
	@$(RM) $(OBJ)

fclean:
	@echo "Removing library and all object files"
	@$(RM) $(NAME) $(OBJ_BONUS) $(OBJ)

re: fclean all

.PHONY: all clean fclean re bclean bonus
