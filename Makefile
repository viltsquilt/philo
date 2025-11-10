# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/14 15:45:37 by vahdekiv          #+#    #+#              #
#    Updated: 2025/11/10 14:02:43 by vahdekiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = main.c parse_input.c philo_utils.c errors_and_cleanup.c \
		safe_functions.c data_init.c dinner.c dinner_utils.c single.c \
		routine_utils.c

O_DIR = objects

OBJS = $(addprefix $(O_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(O_DIR):
		mkdir -p $@

$(O_DIR)/%.o: %.c philo.h | $(O_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf $(O_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
