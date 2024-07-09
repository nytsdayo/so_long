CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

SRCSDIR = srcs/

INIT_SRCS = $(wildcard $(SRCSDIR)init/*.c)
INIT_OBJS = $(INIT_SRCS:$(SRCSDIR)%.c=$(SRCSDIR)%.o)

PLAYER_SRCS = $(wildcard $(SRCSDIR)player/*.c)
PLAYER_OBJS = $(PLAYER_SRCS:$(SRCSDIR)%.c=$(SRCSDIR)%.o)

MAIN_SRC = $(SRCSDIR)main.c
MAIN_OBJ = $(MAIN_SRC:$(SRCSDIR)%.c=%.o)

SRCS = $(INIT_SRCS) $(PLAYER_SRCS) $(MAIN_SRC)
OBJS = $(INIT_OBJS) $(PLAYER_OBJS) $(MAIN_OBJ)

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

FTPRINTFDIR = ft_printf
FTPRINTF = $(FTPRINTFDIR)/libftprintf.a

MLXDIR = minilibx_opengl
MLX = $(MLXDIR)/libmlx.a

INCLUDES = -I./includes -I$(LIBFTDIR) -I$(FTPRINTFDIR) -I$(MLXDIR)
LIBS = $(LIBFT) $(FTPRINTF) $(MLX)
FRAMEWORKS = -framework OpenGL -framework AppKit

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