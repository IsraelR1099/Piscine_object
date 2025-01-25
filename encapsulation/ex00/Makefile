# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 20:28:25 by irifarac          #+#    #+#              #
#    Updated: 2025/01/25 13:18:53 by israel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = divide

OBJ_DIR = obj

SRC = main.cpp \
	  Bank.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))

WARNING_FLAGS := -Wall -Wextra -Werror -Wshadow -Wundef -pedantic -MMD
STD_FLAGS := -std=c++98
DEBUG_FLAGS := -g -Og

CXXFLAGS := $(STD_FLAGS) $(WARNING_FLAGS) $(DEBUG_FLAGS)

all: $(NAME)

-include $(DEP)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creating binary $(NAME)$(RESET)"
	c++ $(OBJ) $(CXXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp Makefile
	@echo "$(GREEN)Compiling.. $<$(RESET)"
	@mkdir -p $(@D)
	c++ $(CXXFLAGS) -c $< -o $@

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


