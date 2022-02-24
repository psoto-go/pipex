# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 16:57:12 by psoto-go          #+#    #+#              #
#    Updated: 2022/02/24 10:43:12 by psoto-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/main.c srcs/parser.c srcs/errors.c srcs/path.c \
					srcs/comands.c srcs/corrects_paths.c srcs/utils.c

OBJS			= $(SRCS:.c=.o)

BONUS			=	srcs_bonus/main.c srcs_bonus/parser.c srcs_bonus/errors.c \
					srcs_bonus/path.c srcs_bonus/comands.c \
					srcs_bonus/corrects_paths.c

BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
CFLAGSANI		= -Wall -Wextra -Werror -fsanitize=address -g3
MAKE			= make
LIBFT			= libft
NAME			= pipex

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) all -C $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

sani:			$(OBJS)
				$(MAKE) all -C $(LIBFT)
				$(CC) $(CFLAGSANI) $(OBJS) libft/libft.a -o $(NAME)

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

.PHONY:			all clean fclean re bonus sani