NAME = server
CLI = client

CFLAGS = -Wall -Wextra -Werror -g

SRC_SERV = server.c minitalk_utils.c
SRC_CLI = client.c

SRC_SERV_BONUS = server_bonus.c minitalk_utils_bonus.c
SRC_CLI_BONUS = client_bonus.c

OBJ_SERV = $(SRC_SERV:.c=.o)
OBJ_CLI = $(SRC_CLI:.c=.o)

OBJ_SERV_BONUS = $(SRC_SERV_BONUS:.c=.o)
OBJ_CLI_BONUS = $(SRC_CLI_BONUS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY:	all re fclean clean libclean bonus

all: $(LIBFT) $(NAME) $(CLI)

$(NAME) : $(OBJ_SERV) $(LIBFT)
	cc $(OBJ_SERV) -L$(LIBFT_DIR) -lft -o $@

$(CLI) : $(OBJ_CLI)
	cc $(OBJ_CLI) -L$(LIBFT_DIR) -lft -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	rm -f *.o

libclean:
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean libclean
	rm -f $(NAME) $(CLI)

bonus: $(LIBFT) $(NAME)_bonus $(CLI)_bonus
	mv $(NAME)_bonus $(NAME)
	mv $(CLI)_bonus $(CLI)

$(NAME)_bonus: $(OBJ_SERV_BONUS) $(LIBFT)
	cc $(OBJ_SERV_BONUS) -L$(LIBFT_DIR) -lft -o $@

$(CLI)_bonus: $(OBJ_CLI_BONUS) $(LIBFT)
	cc $(OBJ_CLI_BONUS) -L$(LIBFT_DIR) -lft -o $@

re: fclean all
