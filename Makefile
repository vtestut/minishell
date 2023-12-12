SRC		:= src/utils/lst2split.c \
src/utils/putstr.c \
src/utils/msh_free_cmdinfo.c \
src/utils/free_split.c \
src/utils/tree_dup.c \
src/utils/free_t_list_heredoc.c \
src/utils/msh_parser_free_data.c \
src/utils/msh_lexer_data_dup.c \
src/utils/tree_free.c \
src/utils/msh_lexer_free_datas.c \
src/main.c \
src/parser/create_command.c \
src/parser/msh_parser_parse.c \
src/parser/msh_parser_exit.c \
src/parser/msh_parser_init.c \
src/parser/msh_parser_token_is_command.c \
src/init/msh_init_exit_error.c \
src/init/msh_init_init.c \
src/init/msh_init_exit.c \
src/exec/exec_gen_tree.c \
src/exec/exec_path_lookup.c \
src/exec/exec_store_heredoc.c \
src/exec/exec_do_redirect.c \
src/exec/exec_tree_v2.c \
src/exec/exec_pipe.c \
src/exec/close_all_pipes.c \
src/exec/check_path.c \
src/exec/exec_child.c \
src/exec/heredoc_get_prompt.c \
src/exec/exec_exit.c \
src/exec/exec_do_heredoc.c \
src/exec/exec_init.c \
src/exec/exec_builtin_non_fork.c \
src/exec/msh_exec.c \
src/exec/exec_gen_cmdinfo.c \
src/exec/add_line.c \
src/exec/h_substitute.c \
src/error/msh_error_init.c \
src/error/msh_error_exit.c \
src/lexer/lexer_token_is_command.c \
src/lexer/msh_lexer_init.c \
src/lexer/substitute_add_tokens.c \
src/lexer/remove_quotes.c \
src/lexer/lexer_token_is_redirection.c \
src/lexer/msh_lexer_init_fsm2.c \
src/lexer/create_lexer_data.c \
src/lexer/msh_lexer_exit.c \
src/lexer/msh_lexer_init_fsm.c \
src/lexer/concat_redirection.c \
src/lexer/msh_lexer_second_pass.c \
src/lexer/msh_lexer_second_pass_concat.c \
src/lexer/msh_lexer_parse.c \
src/io/msh_io_exit.c \
src/io/msh_io_read_input.c \
src/io/msh_io_print_error.c \
src/io/msh_io_init.c \
src/glob/msh_glob_get.c \
src/builtin/exit_shell.c \
src/builtin/unset.c \
src/builtin/is_builtin.c \
src/builtin/exit.c \
src/builtin/export_utils.c \
src/builtin/cd.c \
src/builtin/env.c \
src/builtin/echo.c \
src/builtin/export.c \
src/builtin/pwd.c \
src/env/env_modif.c \
src/env/env_init.c \
src/env/env_get.c \
src/env/env_delete.c \
src/env/env_exit.c \
src/env/msh_env_get_envp.c \
src/env/env_substitute_all.c

OBJ		:= $(SRC:.c=.o)

LIBFT	:= ./libft/libft.a
NAME	:= minishell

CFLAGS	:= -Wall -Wextra -Werror -g -I./include -I./libft -DFT_LIST_CUSTOM_TYPE="\"$(CURDIR)/include/types.h\"" -DFT_BTREE_CUSTOM_TYPE="\"$(CURDIR)/include/types.h\""
LDFLAGS	:= -L./libft -lft -lreadline

all: $(NAME) ;

$(NAME): $(OBJ) $(LIBFT)
	${CC} ${CFLAGS} ${OBJ} ${LDFLAGS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(LIBFT):
	${MAKE} -C libft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	${MAKE} fclean
	${MAKE} all