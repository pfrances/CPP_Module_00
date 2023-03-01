# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 11:07:21 by pfrances          #+#    #+#              #
#    Updated: 2023/03/01 16:18:44 by pfrances         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = accountsGestionary
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -MMD -MP
INCLUDE = -I includes

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
DEPS_DIR = ./deps
SRCS = $(addprefix $(SRCS_DIR)/,	tests.cpp	\
									Account.cpp)
OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.cpp=.o))
DEPS = $(subst $(OBJS_DIR), $(DEPS_DIR), $(OBJS:.o=.d))


all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p $(DEPS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(DEPS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)