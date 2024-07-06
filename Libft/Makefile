# Compiler
CC := cc
AR := ar rcs

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Source files
SRCS := ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c ft_strtrim.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_striteri.c ft_realloc.c

# Object files
OBJS := $(SRCS:.c=.o)

# Target library
NAME := libft.a

BONUS_SRCS := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

# ifdef BONUS
	SRCS += $(BONUS_SRCS)
	OBJS += $(BONUS_OBJS)
# endif
# Default target
all: $(NAME)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Bonus Target
bonus:
	@ $(MAKE)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
# Clean rule
clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

# Clean rule with target library
fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# Phony targets
.PHONY: all clean fclean
