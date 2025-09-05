NAME = server

CLI = client

CFLAGS = -Wall -Wextra -Werror -g

SRC_SERV = server.c

SRC_CLI = client.c

OBJ_SERV = $(SRC_SERV:.c=.o)

OBJ_CLI = $(SRC_CLI:.c=.o)

.PHONY:	libft all re fclean clean
all: libft $(NAME) $(CLI)

$(NAME) : libft $(OBJ_SERV)
	cc $(OBJ_SERV) -L./libft -lft -o $@

$(CLI) : libft $(OBJ_CLI)
	cc $(OBJ_CLI) -L./libft -lft -o $@

libft:
	$(MAKE) -C ./libft all

clean:
	rm -f *.o

libclean:
	$(MAKE) -C ./libft fclean

fclean: clean libclean
	rm -f server client

re: fclean all
