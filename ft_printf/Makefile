# Compiler
CC := cc
AR := ar rcs

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Source files
SRCS := *.c 

# Object files
OBJS := $(SRCS:.c=.o)

# Target library
NAME := libftprintf.a

# Default target
all: $(NAME)
# Rule to build object files
$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
# Rule to build the library
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
# Clean rule
clean:
	rm -f $(OBJS)
	
# Clean rule with target library
fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# Phony targets
.PHONY: all clean fclean re
