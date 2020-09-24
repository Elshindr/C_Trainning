NAME = libft.a

CC = gcc

FLAGS = -Werror -Wextra -Wall

LIB = ar rc
OBJDIR = ./obj/

SRC := $(filter %.c, $(shell find srcs -type f))
OBJ := $(addprefix $(OBJDIR), $(SRC:.c=.o))

INC = -I ./includes/

CLEAN = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	$(CLEAN) -r $(OBJDIR)

fclean: clean
	$(CLEAN) $(NAME)

re: fclean all
