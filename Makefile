# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 20:46:58 by modnosum          #+#    #+#              #
#    Updated: 2018/10/23 19:16:16 by modnosum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft_PATH	:= ./libft
include		$(libft_PATH)/Project.mk

CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -pedantic -g
IFLAGS		+= -I $(INC_DIR)
LFLAGS		+=

SRC_DIR		:= source
INC_DIR		:= include
OBJ_DIR		:= build

SRC_EXT		:= c
OBJ_EXT		:= o

MFLAGS		+= --no-print-directory

NAME		:= modnosum.filler

SRCS		:= $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
OBJS		:= $(patsubst $(SRC_DIR)%.$(SRC_EXT),$(OBJ_DIR)%.$(OBJ_EXT),$(SRCS))
DIRS		:= $(sort $(dir $(OBJS)))

RESET_COLOR	?= \e[0m
RED_COLOR	?= \e[31m
GREEN_COLOR	?= \e[32m

RES_DIR := ./resources
FILLER_VM := $(RES_DIR)/filler_vm
MAPS_DIR := $(RES_DIR)/maps
PLAYERS_DIR := $(RES_DIR)/players

p1-run-%: ./resources/players/%.filler | $(NAME)
	@$(FILLER_VM) -f $(MAPS_DIR)/map00 -p1 ./$(NAME) -p2 $< ; true

p2-run-%: ./resources/players/%.filler | $(NAME)
	@$(FILLER_VM) -f $(MAPS_DIR)/map00 -p1 $< -p2 ./$(NAME) ; true

.MAIN: all
.PHONY: all fclean clean re c f

all: $(NAME)
c: clean
clean:
	@$(MAKE) $(MFLAGS) -C $(libft_PATH) clean
	@rm -fr $(OBJ_DIR)
	@echo "Removed ft_ssl build directory."
f: fclean
fclean: clean
	@$(MAKE) $(MFLAGS) -C $(libft_PATH) fclean
	@rm -fr $(NAME)
	@echo "Removed ft_ssl executable."
re: fclean all

$(OBJ_DIR):
	@mkdir -p $(DIRS)
	@echo "Created ft_ssl build directory."

$(OBJ_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT) | $(OBJ_DIR)
	@$(CC) -o $@ -c $< $(IFLAGS) $(CFLAGS)

$(NAME): $(OBJS) | $(libft_NAME)
	@echo "Finished compiling ft_ssl object files."
	@$(CC) -o $@ $^ $(LFLAGS) $(IFLAGS) $(CFLAGS)
	@echo "Finished ft_ssl."

$(libft_NAME): $(libft_DEPS)
	@$(MAKE) $(MFLAGS) -C $(libft_PATH) all
