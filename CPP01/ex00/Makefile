NAME = zombie
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
CC = c++
SRCS = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp
SRCS_OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME): $(SRCS_OBJS)
		$(CC) $(FLAGS) $(SRCS_OBJS) -o $(NAME)

clean:
		rm -rf $(SRCS_OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all