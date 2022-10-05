# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kokrokhi <kokrokhi@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 16:59:40 by kokrokhi          #+#    #+#              #
#    Updated: 2022/10/05 17:45:42 by kokrokhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang
NAME	= so_long
CFLAGS	= -Wall -Werror -Wextra -ggdb3
HEADER	= -I includes -I Libft/
LIBFT	= Libft/
LIBFT_A = Libft/libft.a

SRCS	=	so_long.c map.c map2.c map3.c

OBJS	= $(SRCS:.c=.o)

NC			:= \033[0m
B_RED		:= \033[1;31m
RED 		:= \033[0;31m
B_GREEN		:= \033[1;32m
GREEN 		:= \033[0;32m
B_BLUE 		:= \033[1;34m
BLUE 		:= \033[0;34m
PURPLE		:= \033[0;35m
B_PURPLE	:= \033[1;35m

SUBM_STATE := $(shell find Libft -type f)

# to automatically initialize the submodules
ifeq ($(SUBM_STATE),)
SUBM_FLAG	= submodule
else 
SUBM_FLAG	= 
endif

all: $(SUBM_STATE) $(LIBFT_A) $(PRINTF_A) $(NAME)

%.o : %.c 
	@echo "$(B_PURPLE)Compiling: $(BLUE)$(notdir $<) 🔨$(NC)"
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

submodule: 
	git submodule init 
	git submodule update

$(LIBFT_A):
	@echo "\n${GREEN}======== libft ========${NC}"
	@$(MAKE) -C $(LIBFT)

SO_LONG: 
	@echo "${GREEN}======== SO_LONG ========${NC}"

$(NAME): SO_LONG $(OBJS)
	@$(CC) $(HEADER) -L$(LIBFT) $(SRCS) $(DEBUG) -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "${B_RED}🧹 Cleaning: ${RED} $(notdir $(OBJS))"
	@$(MAKE) -C $(LIBFT) fclean

fclean: clean
	@rm -f $(NAME)
	@echo "${B_RED}🧹 Cleaning: ${RED} $(NAME)"

re: fclean all

.PHONY: all, libft, clean, fclean