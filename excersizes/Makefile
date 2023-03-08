NAME := megaphone
SRCFILES := megaphone.cpp

CC = c++
CFLAGS = -std=c++98 -Wextra -Werror -Wall
# CFLAGS = -Wextra -Werror -Wall -pthread -g -fsanitize=thread
# CFLAGS = -Wextra -Werror -Wall -pthread -ggdb3 -fsanitize=address
# OBJS := $(SRCFILES:.c=.o) 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCFILES) -o $(NAME) 
clean:
	rm -f $(OBJS)
fclean:	clean
	rm -f $(NAME)
	
re:		fclean all

.PHONY: clean fclean re