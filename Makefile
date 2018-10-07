# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: modnosum <modnosum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/16 20:46:58 by modnosum          #+#    #+#              #
#    Updated: 2018/09/08 23:32:46 by modnosum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		:= ./filler/source
INC_DIR		:= ./filler/include
OBJ_DIR		:= ./filler/build

SRC_EXT		:= c
OBJ_EXT		:= o

libft_PATH	:= ./libft
include		$(libft_PATH)/Project.mk

CC		:= gcc
CFLAGS		:= -Wall -Werror -Wextra -pedantic -g -DDEBUG
IFLAGS		+= -I $(INC_DIR)
LFLAGS		+=

MFLAGS		?= --no-print-directory

NAME		:= modnosum.filler

SRCS		:= $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
OBJS		:= $(patsubst $(SRC_DIR)%.$(SRC_EXT),$(OBJ_DIR)%.$(OBJ_EXT),$(SRCS))
DIRS		:= $(sort $(dir $(OBJS)))

RESET_COLOR	?= \e[0m
RED_COLOR	?= \e[31m
GREEN_COLOR	?= \e[32m

.MAIN: all
.PHONY: all fclean clean re c f

all: $(NAME)
c: clean
clean:
	@rm -fr $(OBJ_DIR)
	@$(call REMOVED_FILE,$(OBJ_DIR))
f: fclean
fclean: clean
	@rm -fr $(NAME)
	@$(call REMOVED_FILE,$(NAME))
re: clean all

$(DIRS):
	@mkdir -p $@

$(OBJ_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT) | $(DIRS)
	@$(CC) -o $@ -c $< $(IFLAGS) $(CFLAGS)
	@$(call CREATED_FILE,$@,$<);

$(libft_NAME): $(libft_DEPS)
	@$(MAKE) $(MFLAGS) -C $(libft_PATH) all

$(NAME): $(OBJS) | $(libft_NAME)
	@$(CC) -o $@ $^ $(LFLAGS) $(IFLAGS) $(CFLAGS)
	@$(call FINISHED_FILE,$@);
