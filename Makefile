# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 11:36:06 by bautrodr          #+#    #+#              #
#    Updated: 2023/12/13 21:01:55 by bautrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[93m
CYAN = \033[96m

SRV = server
CLI = client

SRCS = server.c client.c utils.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

all: $(SRV) $(CLI)

$(SRV): server.o utils.o Makefile minitalk.h
	@echo "$(CYAN)Building $(BOLD)$(SRV)$(RESET)"
	$(CC) $(CFLAGS) server.o utils.o -o $(SRV)
	@echo "$(GREEN)$(BOLD)$(SRV)$(RESET) $(GREEN)built successfully$(RESET)"

$(CLI): client.o utils.o Makefile minitalk.h
	@echo "$(CYAN)Building $(BOLD)$(CLI)$(RESET)"
	$(CC) $(CFLAGS) client.o utils.o -o $(CLI)
	@echo "$(GREEN)$(BOLD)$(CLI)$(RESET) $(GREEN)built successfully$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files$(RESET)"
	rm -f $(OBJS)
	@echo "$(GREEN)Object files cleaned$(RESET)"

fclean: clean
	@echo "$(YELLOW)Cleaning executables$(RESET)"
	rm -f $(SRV)
	rm -f $(CLI)
	@echo "$(GREEN)Executables cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re
