NAME = span

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -MMD -g
CXX = c++

SRCS = main.cpp Span.cpp

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -rf $(OBJS)
		rm -rf $(DEPS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

-include $(DEPS)
