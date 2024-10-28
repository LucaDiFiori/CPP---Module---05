NAME = form_28b
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm home_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)