# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 20:28:25 by irifarac          #+#    #+#              #
#    Updated: 2025/01/31 10:58:08 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = divide

OBJ_DIR = obj
SRC_DIR = src

SRC = $(SRC_DIR)/main.cpp \
	  $(SRC_DIR)/Bank.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))

CC := c++
WARNING_FLAGS := -Wall -Wextra -Werror -Wshadow -Wundef -pedantic -MMD
STD_FLAGS := -std=c++98
DEBUG_FLAGS := -g -Og
INCLUDES := -I./includes

CXXFLAGS := $(STD_FLAGS) $(WARNING_FLAGS) $(DEBUG_FLAGS) $(INCLUDES)

all: $(NAME)

-include $(DEP)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creating binary $(NAME)$(RESET)"
	$(CC) $(OBJ) $(CXXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp Makefile
	@echo "$(GREEN)Compiling.. $<$(RESET)"
	@mkdir -p $(@D)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
ifneq ("$(wildcard $(OBJ) $(DEP) $(OBJ_DIR))", "")
	rm -rf $(OBJ) $(DEP)
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Objetos borrados $(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra $(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutable borrado ✅ $(RESET)"
else
	@echo "$(RED)El ejecutable no existe, no se borra ❌ $(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re


