# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 16:57:12 by psoto-go          #+#    #+#              #
#    Updated: 2022/02/15 13:02:04 by psoto-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/main.c

OBJS			= $(SRCS:.c=.o)

BONUS			=	

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make
LIBFT			= libft
NAME			= pipex

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) all -C $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)


clean:
				$(MAKE) clean -C $(LIBFT)
				$(RM) $(OBJS) $(BONUS_OBJS)



fclean:			clean
				$(MAKE) fclean -C $(LIBFT)
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(BONUS_OBJS)
				$(MAKE) all -C $(LIBFT)
				$(CC) $(CFLAGS) $(BONUS_OBJS) libft/libft.a -o $(NAME)

.PHONY:			all clean fclean re bonus