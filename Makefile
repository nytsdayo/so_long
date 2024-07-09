CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

SRCSDIR = srcs/
SRCS = $(wildcard $(SRCSDIR)*.c)
OBJS = $(SRCS:$(SRCSDIR)%.c=%.o)

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

FTPRINTFDIR = ft_printf
FTPRINTF = $(FTPRINTFDIR)/libftprintf.a

MLXDIR = minilibx_opengl
MLX = $(MLXDIR)/libmlx.a

INCLUDES = -I$(SRCSDIR) -I$(LIBFTDIR) -I$(FTPRINTFDIR) -I$(MLXDIR)
LIBS = $(LIBFT) $(FTPRINTF) $(MLX)
FRAMEWORKS = -framework OpenGL -framework AppKit

Debug: CFLAGS += -g
Debug: all

all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) $(FRAMEWORKS) -o $(NAME)

%.o: $(SRCSDIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(FTPRINTF):
	$(MAKE) -C $(FTPRINTFDIR)

$(MLX):
	$(MAKE) -C $(MLXDIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FTPRINTFDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FTPRINTFDIR) fclean

re: fclean all

.PHONY: all clean fclean re