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
LDFLAGS := -L./minilibx -L./libft -L./printf

# Libraries to link against, including the math library if needed
LDLIBS := -lft -lftprintf -lmlx -framework OpenGL -framework AppKit -lm

LFT = libft/libft.a
PFT = printf/libftprintf.a
MFT = minilibx/libmlx.a
# Source files
SRC = $(wildcard *.c)
	# Add all your source files here
	  
# SRC := $(wildcard src/*.c)
# Object files
OBJ = $(SRC:.c=.o)

# Phony targets for make commands
.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Rule to link the program
$(NAME): $(LFT) $(PFT) $(MFT) $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#
# Rule to clean object files and other temporary files
clean:
	rm -f $(OBJ) $(NAME)
	make -C minilibx clean
	make -C libft clean
	make -C printf clean

# Rule to fully clean the project, including the executable
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C printf fclean

# Rule to re-make the project
re: fclean all

libft/libft.a:
			make -C libft all
printf/libftprintf.a:
			make -C printf all
minilibx/libmlx.a:
			make -C minilibx all

