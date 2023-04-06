NAME := identify
SRCFILES := Base.cpp A.cpp B.cpp C.cpp main.cpp

CC = c++
CFLAGS = -std=c++98 -Wextra -Werror -Wall -Wno-unused -Wconversion -Wfatal-errors 
#-g -fsanitize=address
OBJS = $(SRCFILES:.cpp=.o)
%o: %cpp
	$(CC) $(CFLAGS) -c $(SRCFILES)
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:		fclean all

.PHONY: clean fclean re