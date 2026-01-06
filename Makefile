# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cobussie <cobussie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/08 00:00:00 by                   #+#    #+#              #
#    Updated: 2025/12/12 17:58:51 by cobussie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

SRCS		= push_swap.c \
			parse.c \
			parse_utils.c \
			disorder.c \
			rotate_operations.c \
			reverse_operations.c \
			order_maker.c \
			utils.c \
			chunk_sort.c \
			medium_sort.c \
			radix.c \
			bench_utils.c \
			bench_mode.c \
			sort_utils.c \

BONUS_SRCS	= checker_bonus.c \
			rotate_operations_bonus.c \
			reverse_operations_bonus.c \
			order_maker_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			utils_bonus.c \
			parse_bonus.c \
			parse_utils_bonus.c \


OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror -MMD -MP -g

%.o: %.c
	@echo "compiling $<"
	@cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
	@echo "crating executable $(NAME)..."
	@cc $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
	@echo "done!"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_LIB)
	@echo "creating executable $(BONUS_NAME)..."
	@cc $(CFLAGS) $(BONUS_OBJS) $(LIBFT_LIB) -o $(BONUS_NAME)
	@echo "done!"

$(LIBFT_LIB): make_libft

make_libft:
	@echo "making libft.a library"
	@$(MAKE) -C $(LIBFT_DIR) bonus > /dev/null

bonusre: fclean bonus

clean:
	@echo "cleaning object files"
	@rm -f $(OBJS) $(BONUS_OBJS) $(OBJS:.o=.d) $(BONUS_OBJS:.o=.d)
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null

fclean: clean
	@echo "cleaning executables"
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re bonus make_libft bonusre

-include $(OBJS:.o=.d) $(BONUS_OBJS:.o=.d)
