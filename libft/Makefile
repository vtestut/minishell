SRC		:=	./src/ft_btree/ft_btree_foreach.c\
			./src/ft_btree/ft_btree_delete_type.c\
			./src/ft_btree/ft_btree_dup.c\
			./src/ft_btree/ft_btree_delete.c\
			./src/ft_btree/ft_btree_foreachnd.c\
			./src/ft_btree/ft_btree_create.c\
			./src/ft_toupper.c\
			./src/ft_ctype/ft_isalpha.c\
			./src/ft_ctype/ft_isdigit.c\
			./src/ft_ctype/ft_isalphanum.c\
			./src/ft_ctype/ft_isspace.c\
			./src/ft_string/ft_strcat.c\
			./src/ft_string/ft_strtrim_one.c\
			./src/ft_string/ft_strinsert.c\
			./src/ft_string/ft_strremoven.c\
			./src/ft_string/ft_memcpy.c\
			./src/ft_string/ft_strncpy.c\
			./src/ft_string/ft_memelemset.c\
			./src/ft_string/ft_strtrim.c\
			./src/ft_string/ft_memmove.c\
			./src/ft_string/ft_strcmp.c\
			./src/ft_string/ft_strremove.c\
			./src/ft_string/ft_countc.c\
			./src/ft_string/ft_strcpy.c\
			./src/ft_string/ft_strlen.c\
			./src/ft_string/ft_strreplace.c\
			./src/ft_string/ft_bzero.c\
			./src/ft_string/ft_memset.c\
			./src/ft_string/ft_substr.c\
			./src/ft_string/ft_strchr.c\
			./src/ft_string/ft_itoa.c\
			./src/ft_string/ft_strjoin.c\
			./src/ft_string/ft_strreplacen.c\
			./src/ft_string/rotate.c\
			./src/ft_string/ft_strinsertn.c\
			./src/ft_string/ft_strchr1.c\
			./src/ft_string/ft_memdup.c\
			./src/ft_string/ft_strdup.c\
			./src/ft_string/ft_strlcpy.c\
			./src/ft_split.c\
			./src/ft_math/ft_min.c\
			./src/ft_math/ft_digitat.c\
			./src/ft_math/ft_getdigits.c\
			./src/ft_math/ft_absi.c\
			./src/ft_math/ft_powi.c\
			./src/ft_splitcs.c\
			./src/ft_list/ft_lstat.c\
			./src/ft_list/ft_lstdup.c\
			./src/ft_list/ft_lstaddback.c\
			./src/ft_list/ft_lstaddfront.c\
			./src/ft_list/ft_lstclear.c\
			./src/ft_list/ft_lstnew.c\
			./src/ft_list/ft_lstsize.c\
			./src/ft_list/ft_lstindex.c\
			./src/ft_list/ft_lstiteri.c\
			./src/ft_list/ft_lstappend.c\
			./src/ft_list/ft_lstlast.c\
			./src/ft_putstrfd.c\
			./src/ft_stdlib/ft_calloc.c\
			./src/ft_stdlib/ft_realloc.c\
			./src/ft_stdlib/ft_atoi_long.c\
			./src/ft_stdlib/ft_strtoi.c\
			./src/ft_stdlib/ft_atoi.c\
			./src/ft_stdlib/ft_strtol.c
OBJ     := ${SRC:.c=.o}

CC      := cc
CFLAGS  := -Wall -Werror -Wextra -I. -g

NAME    := libft.a

all:    ${NAME} ;

${NAME}: ${OBJ}
	ar rcs $@ ${OBJ}

%.o:
	${CC} ${CFLAGS} -c -o $@ ${@:.o=.c}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re:
	${MAKE} fclean
	${MAKE} all