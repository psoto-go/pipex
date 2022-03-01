# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 16:57:12 by psoto-go          #+#    #+#              #
#    Updated: 2022/03/01 17:08:43 by psoto-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/main.c srcs/parser.c srcs/errors.c srcs/path.c \
					srcs/comands.c srcs/corrects_paths.c utils/ft_memcpy.c \
					utils/ft_split.c utils/ft_strdup.c utils/ft_strjoin.c  \
					utils/ft_strjoinlks.c utils/ft_strlen.c utils/ft_strncmp.c \
					utils/ft_substr.c utils/ft_isalpha.c

OBJS			= $(SRCS:.c=.o)

BONUS			=	srcs_bonus/main.c srcs_bonus/parser.c srcs_bonus/errors.c srcs_bonus/path.c \
					srcs_bonus/comands.c srcs_bonus/utils_list.c srcs_bonus/corrects_paths.c  \
					utils_bonus/ft_split.c utils_bonus/ft_strdup.c utils_bonus/ft_strjoin.c  \
					utils_bonus/ft_strjoinlks.c utils_bonus/ft_strlen.c utils_bonus/ft_strncmp.c \
					utils_bonus/ft_substr.c utils_bonus/ft_lstadd_back.c utils_bonus/ft_lstclear.c \
					utils_bonus/ft_lstlast.c utils_bonus/ft_lstdelone.c utils_bonus/ft_lstiter.c \
					utils_bonus/ft_memcpy.c utils_bonus/ft_lstsize.c utils_bonus/ft_isalpha.c \
					utils_bonus/get_next_line.c

BONUS_OBJS		= 	srcs_bonus/main.o srcs_bonus/parser.o srcs_bonus/errors.o srcs_bonus/path.o \
					srcs_bonus/comands.o srcs_bonus/utils_list.o srcs_bonus/corrects_paths.o  \
					utils_bonus/ft_split.o utils_bonus/ft_strdup.o utils_bonus/ft_strjoin.o  \
					utils_bonus/ft_strjoinlks.o utils_bonus/ft_strlen.o utils_bonus/ft_strncmp.o \
					utils_bonus/ft_substr.o utils_bonus/ft_lstadd_back.o utils_bonus/ft_lstclear.o \
					utils_bonus/ft_lstlast.o utils_bonus/ft_lstdelone.o utils_bonus/ft_lstiter.o \
					utils_bonus/ft_memcpy.o utils_bonus/ft_lstsize.o utils_bonus/ft_isalpha.o \
					utils_bonus/get_next_line.o

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
CFLAGSANI		= -Wall -Wextra -Werror -fsanitize=address -g3
MAKE			= make
NAME			= pipex

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

sani:			$(OBJS)
				$(CC) $(CFLAGSANI) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus: 			$(BONUS_OBJS)
				@$(MAKE) OBJS="$(BONUS_OBJS)" all

sanibonus:		$(BONUS_OBJS)
				$(CC) $(CFLAGSANI) $(BONUS_OBJS) -o $(NAME)

.PHONY:			all clean fclean re bonus