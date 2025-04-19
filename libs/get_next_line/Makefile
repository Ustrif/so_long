CFILES = get_next_line.c get_next_line_utils.c
OFILES = $(CFILES:.c=.o)
NAME = gnl.a
CFLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OFILES)
	ar r $(NAME) $(OFILES)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re