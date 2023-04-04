NAME := materia
SRCFILES := AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp main.cpp

CC = c++
CFLAGS = -std=c++98 -Wextra -Werror -Wall -Wfatal-errors -g -fsanitize=address
OBJS = $(SRCFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean all

.PHONY: clean fclean re