CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(SRCSDIR) -I$(LIBFTDIR)
MINILIBX = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
SRCSDIR = srcs/
SRCS = $(wildcard $(SRCSDIR)*.c)
OBJS = $(SRCS:$(SRCSDIR)%.c=%.o)
LIBFTDIR = Libft
LIBFT = $(LIBFTDIR)/libft.a
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)

%.o: $(SRCSDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
