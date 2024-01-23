NAME = a.out
FLAGS = -Wall -Wextra -Werror -std=c++98 -g
CC = c++
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
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
