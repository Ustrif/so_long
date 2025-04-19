CFILES = so_long.c sources/ft_printf.c sources/gamefile.c sources/utils.c \
	sources/gamefile1.c sources/utils1.c sources/gamefile2.c \
	sources/utils2.c sources/utils3.c sources/utils4.c
LIBFT = libs/libft/libft.a
LIBGNL = libs/get_next_line/gnl.a
LIBX = libs/minilibx/libmlx_Linux.a
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -lX11 -lXext -lm
NAME = so_long

all: libs $(NAME)

libs:
	$(MAKE) -C libs/libft
	$(MAKE) -C libs/get_next_line
	$(MAKE) -C libs/minilibx

$(NAME): $(CFILES) $(LIBFT) $(LIBGNL) $(LIBX)
	$(CC) $(CFLAGS) $(CFILES) $(LIBFT) $(LIBGNL) $(LIBX) $(LFLAGS) -o $(NAME)

clean:
	$(MAKE) -C libs/libft clean
	$(MAKE) -C libs/get_next_line clean

fclean: clean
	rm -rf $(NAME) $(LIBFT) $(LIBGNL) $(LIBX)
	$(MAKE) -C libs/libft fclean
	$(MAKE) -C libs/get_next_line fclean
	$(MAKE) -C libs/minilibx clean

re: fclean all

.PHONY: all re clean fclean libs