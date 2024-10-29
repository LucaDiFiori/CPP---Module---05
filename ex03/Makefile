NAME = make_coffee
CC = g++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@test -e home_shrubbery && rm home_shrubbery || true

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)