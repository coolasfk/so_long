# Name of the executable
NAME = so_long

# Compiler
CC = gcc 
# gcc -g -o so_long so_long.c
# Compiler flags
#CFLAGS = -Wall -Wextra -Werror -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-unused-parameter -Wno-unused-variable -Wno-sign-compare
CFLAGS := -Wall -Wextra -Werror -g -Iheaders/ 
# Include paths for header files

# Library paths
LDFLAGS := -L./minilibx 

# Libraries to link against, including the math library if needed
LDLIBS := -lmlx -framework OpenGL -framework AppKit -lm

# Source files
SRC = $(wildcard *.c)\
      $(wildcard gnl/*.c) \
      $(wildcard libft/ft_*.c) \
      $(wildcard printf/ft_*.c) \
      $(wildcard mlx/*.c) 
      # Add all your source files here
	  
# SRC := $(wildcard src/*.c)
# Object files
OBJ = $(SRC:.c=.o)

# Phony targets for make commands
.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Rule to link the program
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#
# Rule to clean object files and other temporary files
clean:
	rm -f $(OBJ) $(NAME)

# Rule to fully clean the project, including the executable
fclean: clean
	rm -f $(NAME)

# Rule to re-make the project
re: fclean all
