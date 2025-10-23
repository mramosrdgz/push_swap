# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariramo <mariramo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/09 11:01:43 by mariramo          #+#    #+#              #
#    Updated: 2025/08/09 11:01:43 by mariramo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = includes

SRCS        = $(wildcard $(SRC_DIR)/*.c)

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

all: $(NAME)
