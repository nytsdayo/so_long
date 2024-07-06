CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(SRCSDIR) -I$(LIBFTDIR) -I$(FTPRINTFDIR)
MINILIBX = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
SRCSDIR = srcs/
SRCS = $(wildcard $(SRCSDIR)*.c)
OBJS = $(SRCS:$(SRCSDIR)%.c=%.o)
FTPRINTFDIR = ft_printf
FTPRINTF = $(FTPRINTFDIR)/libftprintf.a
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(FTPRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(FTPRINTF) $(LIBFT) $(MINILIBX) -o $(NAME)

%.o: $(SRCSDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTFDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(FTPRINTFDIR) clean
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FTPRINTFDIR) fclean
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
