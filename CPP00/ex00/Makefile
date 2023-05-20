NAME := megaphone
SRCFILES := megaphone.cpp

CPP = c++
CFLAGS = -std=c++98 -Wextra -Werror -Wall
OBJ = $(SRCFILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $^ -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re:		fclean all

.PHONY: clean fclean re