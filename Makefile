#Executable name
NAME = push_swap

#Compilator and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Variables
FILES = main.c error_check.c push_swap_utils.c sort_functions.c sorting.c sorting_extra.c sorting_utils.c stack_utils.c
OBJECTS = $(FILES:.c=.o)

# Library path
LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

#Default rule: compile all
all: $(LIBFT) $(NAME)

#Rule to create the program
$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(LIBDIR) -lft -o $(NAME)

%.o: %.c push_swap.h $(LIBDIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBDIR) all

#Rule to clean all the created files
clean:
	$(MAKE) -C $(LIBDIR) clean
	rm -f $(OBJECTS) $(B_OBJECTS)

#Rule to clean all, including the library
fclean: clean
	$(MAKE) -C $(LIBDIR) fclean
	rm -f $(NAME)

#Rule to recompile all
re: fclean all

#Indicates that the next rules are not files
.PHONY: all clean fclean re bonus