NAME = RPN

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -g

SRCS = main.cpp RPN.cpp
SRCS_OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(SRCS_OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS_OBJS) -o $(NAME)

clean:
		rm -rf $(SRCS_OBJS)
		rm -rf $(DEPS)

fclean: clean
		rm -rf $(DEPS)

re: fclean all

-include $(DEPS)

