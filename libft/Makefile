#Executable name
NAME = libft.a

#Compilator and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

#Variables
FILES = ft_atoi.c		ft_putendl_fd.c	ft_strncmp.c	ft_bzero.c		ft_putnbr_fd.c	\
		ft_strnstr.c	ft_calloc.c		ft_putstr_fd.c	ft_strrchr.c	ft_isalnum.c	\
		ft_split.c		ft_strtrim.c	ft_isalpha.c	ft_strchr.c		ft_substr.c		\
		ft_isascii.c	ft_strdup.c		ft_tolower.c	ft_isdigit.c	ft_memchr.c		\
		ft_striteri.c	ft_isprint.c	ft_memcmp.c		ft_strjoin.c	ft_itoa.c		\
		ft_memcpy.c		ft_strlcat.c	ft_memmove.c	ft_strlcpy.c	ft_toupper.c	\
		ft_memset.c		ft_strlen.c		ft_putchar_fd.c	ft_strmapi.c	ft_printf.c		\
		ft_printf_utils.c
OBJECTS = $(FILES:.c=.o)
BONUS = ft_lstadd_back_bonus.c	ft_lstdelone_bonus.c	ft_lstmap_bonus.c				\
		ft_lstadd_front_bonus.c	ft_lstiter_bonus.c		ft_lstnew_bonus.c				\
		ft_lstclear_bonus.c		ft_lstlast_bonus.c		ft_lstsize_bonus.c
B_OBJECTS = $(BONUS:.c=.o)

#Default rule: compile all
all: $(NAME)

#Rule to create the library
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

#Rule to clean all the created files
clean:
	rm -f $(OBJECTS) $(B_OBJECTS)

#Rule to clean all, including the library
fclean: clean
	rm -f $(NAME)

#Rule to recompile all
re: fclean all

#Rule to add bonus files to the library compilation
bonus: $(B_OBJECTS)
	$(CC) $(CFLAGS) -c $(BONUS)
	ar rcs $(NAME) $(B_OBJECTS)

#Indicates that the next rules are not files
.PHONY: all clean fclean re bonus
