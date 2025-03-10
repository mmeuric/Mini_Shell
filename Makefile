# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeuric <mmeuric@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 14:04:53 by mmeuric           #+#    #+#              #
#    Updated: 2025/03/06 14:05:01 by mmeuric          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

ifeq ($(shell uname -s), Darwin)

RL_PATH =$(shell brew --prefix readline)

endif

LIB = -L $(RL_PATH)/lib -lreadline

CFLAGS = -Wall -Wextra -Iinclude -I$(RL_PATH)/include # -fsanitize=address -g

OBJSFOLDER = objs/

SRCS_LEXER = lexer.c \
			 lexer_utils.c \
			 lexer_utils2.c \
			 tok_list.c

SRCS_PARSER = parser.c

SRCS_AST = ast.c \
		   ast_utils.c \
		   ast_utils2.c \
		   rdescent.c

SRCS_ERR = error.c

SRCS_EXE = executor.c \
		   exec_binary.c \
		   exec_unary.c \
		   exec_utils.c \
		   exec_utils2.c

SRCS_EXPAND = expander.c \
			  expander_utils.c \
			  string_list.c \
			  string_list_utils.c \
			  wild_card.c

SRCS_SB = sb.c \
		  sb_utils.c

SRCS_HEREDOC = heredoc.c

SRCS_SIGNALS = signals.c

SRCS_DEBUG = debug_tree.c \
			 debug_tree_utils.c

BUILTINS_FOLD = src/minishell_builtins/

BUILTINS_FILES = builtin_dispatcher.c \
				global_utils.c \
				global_utils2.c \
				lst_operations.c \
				parse_utils.c \
				src/cd/cd.c \
				src/cd/cds_nuts.c \
				src/cd/path_utils.c \
				src/echo/echo.c \
				src/echo/echo_utils.c \
				src/env/env.c \
				src/env/env_utils.c \
				src/exit/exit.c \
				src/export/export.c \
				src/export/export_utils.c \
				src/export/validation_utils.c \
				src/pwd/pwd.c \
				src/pwd/pwd_utils.c \
				src/unset/unset.c \
				src/unset/unset_utils.c

SRCS_HACKS		= hacks.c

SRCS_BUILTINS = $(foreach file, $(BUILTINS_FILES), $(BUILTINS_FOLD)$(file))

OBJS_FILES = $(SRCS_LEXER:.c=.o) \
			 $(SRCS_PARSER:.c=.o) \
			 $(SRCS_AST:.c=.o) \
			 $(SRCS_ERR:.c=.o) \
			 $(SRCS_EXE:.c=.o) \
			 $(SRCS_SB:.c=.o) \
			 $(SRCS_EXPAND:.c=.o) \
			 $(SRCS_HEREDOC:.c=.o) \
			 $(SRCS_SIGNALS:.c=.o) \
			 $(SRCS_HACKS:.c=.o) \
			 $(SRCS_DEBUG:.c=.o) \
			 main.o

LIBFT = src/libft/libft.a

OBJS = $(foreach obj, $(OBJS_FILES), $(OBJSFOLDER)$(obj))

GLOBAL_HEADERS = include/globals.h

L_BUILTINS = $(BUILTINS_FOLD)/libbuiltins.a

all: $(OBJSFOLDER) $(LIBFT) $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C src/libft

$(OBJSFOLDER):
	@mkdir objs

$(L_BUILTINS): $(SRCS_BUILTINS)
	make -C $(BUILTINS_FOLD)

$(NAME): $(OBJS) $(L_BUILTINS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) -L$(BUILTINS_FOLD) -lbuiltins -Lsrc/libft -lft $(LIB)

$(OBJSFOLDER)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/lexer/%.c include/lexer.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/parser/%.c include/parser.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/parser/ast/%.c include/ast.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/execution/%.c include/executor.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/expander/%.c include/expander.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/stringbuilder/%.c include/stringbuilder.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/error/%.c include/error.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/heredoc/%.c include/heredoc.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/signals/%.c include/signals.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/hacks/%.c include/hacks.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJSFOLDER)%.o: src/debug/%.c include/debug.h $(GLOBAL_HEADERS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -rf $(NAME)
	make fclean -C src/libft

clean:
	rm -rf $(OBJS)
	make clean -C src/libft

.PHONY: all clean fclean re
