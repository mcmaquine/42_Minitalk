NAME = server
CLI = client

CFLAGS = -Wall -Wextra -Werror -g

SRC_SERV = server.c minitalk_utils.c
SRC_CLI = client.c

OBJ_SERV = $(SRC_SERV:.c=.o)
OBJ_CLI = $(SRC_CLI:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY:	all re fclean clean libclean

all: $(LIBFT) $(NAME) $(CLI)

$(NAME) : $(OBJ_SERV) $(LIBFT)
	cc $(OBJ_SERV) -L$(LIBFT_DIR) -lft -o $@

$(CLI) : $(OBJ_CLI)
	cc $(OBJ_CLI) -L$(LIBFT_DIR) -lft -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	rm -f $(OBJ_SERV) $(OBJ_CLI)

libclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean libclean
	rm -f $(NAME) $(CLI)

re: fclean all
