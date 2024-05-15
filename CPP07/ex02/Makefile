NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g

SRCS_FILES = main.cpp
SRCS_OBJS = $(SRCS_FILES:.cpp=.o)
DEPS = $(SRCS_FILES:.cpp=.d)

all: $(NAME)

$(NAME): $(SRCS_OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS_OBJS) -o $(NAME)

clean:
		rm -rf $(SRCS_OBJS)
		rm -rf $(DEPS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

-include $(DEPS)
