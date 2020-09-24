NAME = display_file

SRC = ft_display_file.c

CC = gcc

FLAGS = -Werror -Wextra -Wall

CLEAN = rm -f

OBJ = display_file.o

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRC)

clean:
	$(CLEAN) $(OBJ)

fclean: clean
	$(CLEAN) $(NAME)

re: fclean all
