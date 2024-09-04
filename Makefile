# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozon <gozon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 08:35:14 by gozon             #+#    #+#              #
#    Updated: 2024/09/04 08:15:49 by gozon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

V = false

ifeq ($(V),true)
    ECHO =
else
    ECHO = @
endif

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = Libft/libft.a
SRC = srcs/child_process.c srcs/files.c srcs/free_arrays.c srcs/get_cmds.c \
	srcs/main.c srcs/pipes.c srcs/pipex.c srcs/processes_operations.c
OBJ_DIR = objects
SRC_DIR = srcs
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Symboles Unicode
CHECK_MARK = ✔
UNCHECKED_MARK = ✘
COMP_SUCCESS = $(CHECK_MARK)
COMP_FAILURE = $(UNCHECKED_MARK)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation de $(NAME) en cours..."
	@$(ECHO)make -C Libft --silent --no-print-directory \
	&& { echo "Compilation de la Libft ($(COMP_SUCCESS))" ; } \
	|| { echo "Erreur : Compilation de la Libft échouée ($(COMP_FAILURE))" ; exit 1; }
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) \
	&& { echo "$(NAME) a été créé avec succès ($(COMP_SUCCESS))" ; } \
	|| { echo "Erreur : Compilation de $(NAME) échouée ($(COMP_FAILURE))" ; exit 1; }
	@echo "Compilation réussie ($(COMP_SUCCESS))"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	$(ECHO)make clean -C Libft --silent --no-print-directory
	$(ECHO)rm -rf $(OBJ_DIR)
	@echo "Nettoyage réussi ($(COMP_SUCCESS))"

fclean: clean
	$(ECHO)rm -f $(NAME)
	$(ECHO)rm -f Libft/libft.a
	@echo "Nettoyage complet réussie ($(COMP_SUCCESS))"

re: fclean all

.PHONY: all clean fclean re

