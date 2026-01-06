# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 18:04:20 by cobussie          #+#    #+#              #
#    Updated: 2025/12/09 11:24:02 by cobussie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
BONUS_DONE = .bonus_done

SRCS =	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c 	\
		ft_strlcpy.c	\
		ft_strlen.c 	\
		ft_strmapi.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_tolower.c	\
		ft_toupper.c	

BONUS =	        ft_lstadd_back_bonus.c	\
		ft_lstadd_front_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstdelone_bonus.c	\
		ft_lstiter_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstmap_bonus.c		\
		ft_lstnew_bonus.c		\
		ft_lstsize_bonus.c		\
		print_char_bonus.c		\
		print_counter_bonus.c	\
		print_errors_bonus.c	\
		print_hex_bonus.c		\
		print_hex_utils_bonus.c	\
		print_int_bonus.c		\
		print_int_utils_bonus.c	\
		print_pointer_bonus.c	\
		print_percent_bonus.c	\
		print_str_bonus.c		\
		print_unsigned_int_bonus.c	\
		utils_bonus.c			\
		ft_printf_bonus.c		\
		format_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)
D_FILES = $(OBJS:.o=.d)
D_BONUS_FILES = $(BONUS_OBJS:.o=.d)

CC = cc
FLAGS = -Wall -Wextra -Werror -MP -MMD

%.o:  %.c 
	$(CC) $(FLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

$(BONUS_DONE): $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	touch $(BONUS_DONE)

bonus: $(BONUS_DONE)


clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(BONUS_DONE) $(D_FILES) $(D_BONUS_FILES)

fclean: clean
	rm -f $(NAME)
	

re: fclean all

.PHONY: all clean fclean re bonus

-include $(D_FILES) $(D_BONUS_FILES)